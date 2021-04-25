/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the EnumHelper class
 */

#ifndef ENUMHELPER_HDR_H
#define ENUMHELPER_HDR_H

#include <string>

#include "AppDefinitions.h"

using namespace std;

class EnumHelper {

public:

    static SensitivityPrefEnum string_to_enum_sensitivity_pref(string enum_str); // A static function that converts an input string to a SensitivityPrefEnum
    static AccountStatusEnum string_to_acct_status(string enum_str); // A static function that converts an input string to a AccountStatusEnum
    
    static string enum_sensitivity_pref_to_string(SensitivityPrefEnum s_pref); // A static function that converts SensitivityPrefEnum to a string output
    static string enum_acct_status_to_string(AccountStatusEnum acct_status); // A static function that converts AccountStatusEnum to a string output

};

#endif

