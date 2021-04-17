#include "EnumHelper.h"

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

string EnumHelper::enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref) {

	switch (s_pref)
	{
	case SensitivityPrefEnum::MILD:
		return "MILD";
	case SensitivityPrefEnum::MODERATE:
		return "MODERATE";
	case SensitivityPrefEnum::HIGH:
		return "HIGH";
	}

}

string EnumHelper::enum_acct_status_to_string(AccountStatusEnum acct_status) {

	switch (acct_status)
	{
	case AccountStatusEnum::ACTIVE:
		return "ACTIVE";
	case AccountStatusEnum::INACTIVE:
		return "INACTIVE";
	case AccountStatusEnum::DISABLED:
		return "DISABLED";
	}

}
