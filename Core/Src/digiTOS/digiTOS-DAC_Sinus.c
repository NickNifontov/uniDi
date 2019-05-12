/*
 * digiTOS-DAC_Sinus.c
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */


#include "digiTOS-DAC_Sinus.h"

volatile uint16_t sin_step=0;

 // Sinus table with 480 point Height
 volatile uint16_t sin_data[SinRes] =

 {1, 26, 51, 76, 100, 125, 150, 175, 200, 225, 250, 274, 299, 324, 349, 373, 398, 423,
		 448, 472, 497, 522, 546, 571, 595, 620, 645, 669, 693, 718, 742, 767, 791,
		 815, 840, 864, 888, 912, 936, 960, 985, 1009, 1032, 1056, 1080, 1104, 1128,
		 1152, 1175, 1199, 1222, 1246, 1269, 1293, 1316, 1340, 1363, 1386, 1409, 1432,
		 1455, 1478, 1501, 1524, 1547, 1569, 1592, 1614, 1637, 1659, 1682, 1704, 1726,
		 1748, 1770, 1792, 1814, 1836, 1858, 1879, 1901, 1922, 1944, 1965, 1986, 2008,
		 2029, 2050, 2071, 2091, 2112, 2133, 2153, 2174, 2194, 2214, 2235, 2255, 2275,
		 2295, 2314, 2334, 2354, 2373, 2392, 2412, 2431, 2450, 2469, 2488, 2507, 2525,
		 2544, 2562, 2580, 2599, 2617, 2635, 2653, 2670, 2688, 2706, 2723, 2740, 2757,
		 2774, 2791, 2808, 2825, 2842, 2858, 2874, 2891, 2907, 2923, 2938, 2954, 2970,
		 2985, 3001, 3016, 3031, 3046, 3061, 3075, 3090, 3104, 3119, 3133, 3147, 3161,
		 3174, 3188, 3201, 3215, 3228, 3241, 3254, 3267, 3279, 3292, 3304, 3316, 3329,
		 3341, 3352, 3364, 3375, 3387, 3398, 3409, 3420, 3431, 3441, 3452, 3462, 3472,
		 3483, 3492, 3502, 3512, 3521, 3530, 3540, 3549, 3557, 3566, 3575, 3583, 3591,
		 3599, 3607, 3615, 3623, 3630, 3637, 3645, 3652, 3658, 3665, 3672, 3678, 3684,
		 3690, 3696, 3702, 3707, 3713, 3718, 3723, 3728, 3733, 3737, 3742, 3746, 3750,
		 3754, 3758, 3762, 3765, 3768, 3772, 3775, 3778, 3780, 3783, 3785, 3787, 3789,
		 3791, 3793, 3794, 3796, 3797, 3798, 3799, 3800, 3800, 3801, 3801, 3801, 3801,
		 3801, 3800, 3800, 3799, 3798, 3797, 3796, 3794, 3793, 3791, 3789, 3787, 3785,
		 3783, 3780, 3778, 3775, 3772, 3768, 3765, 3762, 3758, 3754, 3750, 3746, 3742,
		 3737, 3733, 3728, 3723, 3718, 3713, 3707, 3702, 3696, 3690, 3684, 3678, 3672,
		 3665, 3658, 3652, 3645, 3637, 3630, 3623, 3615, 3607, 3599, 3591, 3583, 3575,
		 3566, 3557, 3549, 3540, 3530, 3521, 3512, 3502, 3492, 3483, 3472, 3462, 3452,
		 3441, 3431, 3420, 3409, 3398, 3387, 3375, 3364, 3352, 3341, 3329, 3316, 3304,
		 3292, 3279, 3267, 3254, 3241, 3228, 3215, 3201, 3188, 3174, 3161, 3147, 3133,
		 3119, 3104, 3090, 3075, 3061, 3046, 3031, 3016, 3001, 2985, 2970, 2954, 2938,
		 2923, 2907, 2891, 2874, 2858, 2842, 2825, 2808, 2791, 2774, 2757, 2740, 2723,
		 2706, 2688, 2670, 2653, 2635, 2617, 2599, 2580, 2562, 2544, 2525, 2507, 2488,
		 2469, 2450, 2431, 2412, 2392, 2373, 2354, 2334, 2314, 2295, 2275, 2255, 2235,
		 2214, 2194, 2174, 2153, 2133, 2112, 2091, 2071, 2050, 2029, 2008, 1986, 1965,
		 1944, 1922, 1901, 1879, 1858, 1836, 1814, 1792, 1770, 1748, 1726, 1704, 1682,
		 1659, 1637, 1614, 1592, 1569, 1547, 1524, 1501, 1478, 1455, 1432, 1409, 1386,
		 1363, 1340, 1316, 1293, 1269, 1246, 1222, 1199, 1175, 1152, 1128, 1104, 1080,
		 1056, 1032, 1009, 985, 960, 936, 912, 888, 864, 840, 815, 791, 767, 742, 718,
		 693, 669, 645, 620, 595, 571, 546, 522, 497, 472, 448, 423, 398, 373, 349, 324,
		 299, 274, 250, 225, 200, 175, 150, 125, 100, 76, 51, 26};

uint16_t GetSinus() {
	if ((sin_step>=SinRes) || (sin_step<=CurrentMargin)|| (sin_step>=(SinRes-CurrentMargin))) {

		return 0;
	}

	return sin_data[sin_step];
}

 void Set_DAC_SINUS_ZERO() {
	 HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1,DAC_ALIGN_12B_R,0);
 }

 void DAC_SINUS_INIT() {
	 HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
	 Set_DAC_SINUS_ZERO();
 }

void DAC_SINUS_ON() {
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start_IT(&htim2);
	Set_DAC_SINUS_ZERO();
	IsSinus=1;
 }


void DAC_SINUS_OFF() {
	Set_DAC_SINUS_ZERO();
	HAL_TIM_Base_Stop(&htim2);
	HAL_TIM_Base_Stop_IT(&htim2);
	IsSinus=0;
 }

