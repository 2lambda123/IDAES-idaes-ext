#include "props_sp.h"
#include<iostream>
#include<stdlib.h>

prop_memo_table22 memo_table_internal_energy_sp;
prop_memo_table22 memo_table_enthalpy_sp;
prop_memo_table22 memo_table_gibbs_sp;
prop_memo_table22 memo_table_helmholtz_sp;
prop_memo_table22 memo_table_isochoric_heat_capacity_sp;
prop_memo_table22 memo_table_isobaric_heat_capacity_sp;
prop_memo_table22 memo_table_speed_of_sound_sp;
prop_memo_table22 memo_table_specific_volume_sp;

//u
PROP_SP_SINGLE_PHASE(internal_energy_vap_sp, memo2_internal_energy, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(internal_energy_liq_sp, memo2_internal_energy, memo2_delta_liquid)
PROP_SP_GENERAL(internal_energy_sp, internal_energy_liq_sp, internal_energy_vap_sp)
MEMO2_FUNCTION(memo2_internal_energy_sp, internal_energy_sp, memo_table_internal_energy_sp)

//s
PROP_SP_SINGLE_PHASE(enthalpy_vap_sp, memo2_enthalpy, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(enthalpy_liq_sp, memo2_enthalpy, memo2_delta_liquid)
PROP_SP_GENERAL(enthalpy_sp, enthalpy_liq_sp, enthalpy_vap_sp)
MEMO2_FUNCTION(memo2_enthalpy_sp, enthalpy_sp, memo_table_enthalpy_sp)

//g
PROP_SP_SINGLE_PHASE(gibbs_vap_sp, memo2_gibbs, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(gibbs_liq_sp, memo2_gibbs, memo2_delta_liquid)
PROP_SP_GENERAL(gibbs_sp, gibbs_liq_sp, gibbs_vap_sp)
MEMO2_FUNCTION(memo2_gibbs_sp, gibbs_sp, memo_table_gibbs_sp)

//f
PROP_SP_SINGLE_PHASE(helmholtz_vap_sp, memo2_helmholtz, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(helmholtz_liq_sp, memo2_helmholtz, memo2_delta_liquid)
PROP_SP_GENERAL(helmholtz_sp, helmholtz_liq_sp, helmholtz_vap_sp)
MEMO2_FUNCTION(memo2_helmholtz_sp, helmholtz_sp, memo_table_helmholtz_sp)

//cv
PROP_SP_SINGLE_PHASE(isochoric_heat_capacity_vap_sp, memo2_isochoric_heat_capacity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(isochoric_heat_capacity_liq_sp, memo2_isochoric_heat_capacity, memo2_delta_liquid)
PROP_SP_GENERAL(isochoric_heat_capacity_sp, isochoric_heat_capacity_liq_sp, isochoric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isochoric_heat_capacity_sp, isochoric_heat_capacity_sp, memo_table_isochoric_heat_capacity_sp)

//cp
PROP_SP_SINGLE_PHASE(isobaric_heat_capacity_vap_sp, memo2_isobaric_heat_capacity, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(isobaric_heat_capacity_liq_sp, memo2_isobaric_heat_capacity, memo2_delta_liquid)
PROP_SP_GENERAL(isobaric_heat_capacity_sp, isobaric_heat_capacity_liq_sp, isobaric_heat_capacity_vap_sp)
MEMO2_FUNCTION(memo2_isobaric_heat_capacity_sp, isobaric_heat_capacity_sp, memo_table_isobaric_heat_capacity_sp)

//w (doesn't really mean much in the two phase region, so use with care)
PROP_SP_SINGLE_PHASE(speed_of_sound_vap_sp, memo2_speed_of_sound, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(speed_of_sound_liq_sp, memo2_speed_of_sound, memo2_delta_liquid)
PROP_SP_GENERAL(speed_of_sound_sp, speed_of_sound_liq_sp, speed_of_sound_vap_sp)
MEMO2_FUNCTION(memo2_speed_of_sound_sp, speed_of_sound_sp, memo_table_speed_of_sound_sp)

//v
PROP_SP_SINGLE_PHASE(specific_volume_vap_sp, memo2_specific_volume, memo2_delta_vapor)
PROP_SP_SINGLE_PHASE(specific_volume_liq_sp, memo2_specific_volume, memo2_delta_liquid)
PROP_SP_GENERAL(specific_volume_sp, specific_volume_liq_sp, specific_volume_vap_sp)
MEMO2_FUNCTION(memo2_specific_volume_sp, specific_volume_sp, memo_table_specific_volume_sp)

