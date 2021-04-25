/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the impementation file for the EnumHelper class. The purpose of class
 * 	        is to convert enums like SensitivityPrefEnum and AccountStatusEnum to string
 * 	        and vice-versa
 */

#include "EnumHelper.h"

// A static function that converts an input string to a SensitivityPrefEnum
SensitivityPrefEnum EnumHelper::string_to_enum_sensitivity_pref(string enum_str) {

	if (enum_str == "MILD") {
		return SensitivityPrefEnum::MILD;
	}
	else if (enum_str == "MODERATE") {
		return SensitivityPrefEnum::MODERATE;
	}
	else if (enum_str == "HIGH") {
		return SensitivityPrefEnum::HIGH;
	}
	else {
		return SensitivityPrefEnum::MILD;
	}

}

// A static function that converts an input string to a AccountStatusEnum
AccountStatusEnum EnumHelper::string_to_acct_status(string enum_str) {

	if (enum_str == "ACTIVE") {
		return AccountStatusEnum::ACTIVE;
	}
	else if (enum_str == "INACTIVE") {
		return AccountStatusEnum::INACTIVE;
	}
	else if (enum_str == "DISABLED") {
		return AccountStatusEnum::DISABLED;
	}
	else {
		return AccountStatusEnum::ACTIVE;
	}

}

// A static function that converts SensitivityPrefEnum to a string output
string EnumHelper::enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref) {

	switch (s_pref)
	{
	case SensitivityPrefEnum::MILD:
		return "MILD";
	case SensitivityPrefEnum::MODERATE:
		return "MODERATE";
	case SensitivityPrefEnum::HIGH:
		return "HIGH";
	default:
		return "MILD";
	}
}

// A static function that converts AccountStatusEnum to a string output
string EnumHelper::enum_acct_status_to_string(AccountStatusEnum acct_status) {

	switch (acct_status)
	{
	case AccountStatusEnum::ACTIVE:
		return "ACTIVE";
	case AccountStatusEnum::INACTIVE:
		return "INACTIVE";
	case AccountStatusEnum::DISABLED:
		return "DISABLED";
	default:
		return "ACTIVE";
	}

}
