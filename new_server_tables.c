/* -*- mode: c -*- */
/* $Id$ */

/* Copyright (C) 2006-2007 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "config.h"
#include "settings.h"
#include "ej_types.h"
#include "ej_limits.h"

#include "new-server.h"
#include "new_server_proto.h"

#include <stdarg.h>

#if CONF_HAS_LIBINTL - 0 == 1
#include <libintl.h>
#define _(x) gettext(x)
#else
#define _(x) x
#endif
#define __(x) x

const unsigned char * const ns_submit_button_labels[NEW_SRV_ACTION_LAST]=
{
  [NEW_SRV_ACTION_UPDATE_STANDINGS_1] = __("Update public standings"),
  [NEW_SRV_ACTION_RESET_1] = __("Reset the contest!"),
  [NEW_SRV_ACTION_SUSPEND] = __("Suspend clients"),
  [NEW_SRV_ACTION_RESUME] = __("Resume clients"),
  [NEW_SRV_ACTION_TEST_SUSPEND] = __("Suspend testing"),
  [NEW_SRV_ACTION_TEST_RESUME] = __("Resume testing"),
  [NEW_SRV_ACTION_PRINT_SUSPEND] = __("Suspend printing"),
  [NEW_SRV_ACTION_PRINT_RESUME] = __("Resume printing"),
  [NEW_SRV_ACTION_SET_JUDGING_MODE] = __("Set judging mode"),
  [NEW_SRV_ACTION_SET_ACCEPTING_MODE] = __("Set accepting mode"),
  [NEW_SRV_ACTION_GENERATE_PASSWORDS_1] = __("Regenerate contest passwords!"),
  [NEW_SRV_ACTION_CLEAR_PASSWORDS_1] = __("Clear contest passwords!"),
  [NEW_SRV_ACTION_GENERATE_REG_PASSWORDS_1] = __("Regenerate registration passwords!"),
  [NEW_SRV_ACTION_RELOAD_SERVER] = __("Reload config files"),
  [NEW_SRV_ACTION_PRIV_SUBMIT_CLAR] = __("Send clarification"),
  [NEW_SRV_ACTION_CHANGE_PASSWORD] = __("Change password"),
  [NEW_SRV_ACTION_CHANGE_LANGUAGE] = __("Switch language"),
  [NEW_SRV_ACTION_RESET_FILTER] = __("Reset filter"),
  [NEW_SRV_ACTION_CLEAR_RUN] = __("Clear this entry"),
  [NEW_SRV_ACTION_CHANGE_STATUS] = __("Change"),
  [NEW_SRV_ACTION_REJUDGE_ALL_1] = __("Rejudge all"),
  [NEW_SRV_ACTION_REJUDGE_SUSPENDED_1] = __("Judge suspended runs"),
  [NEW_SRV_ACTION_REJUDGE_DISPLAYED_1] = __("Rejudge displayed runs"),
  [NEW_SRV_ACTION_FULL_REJUDGE_DISPLAYED_1] = __("Full rejudge displayed runs"),
  [NEW_SRV_ACTION_SQUEEZE_RUNS] = __("Squeeze runs"),
  [NEW_SRV_ACTION_RESET_CLAR_FILTER] = __("Reset filter"),
  [NEW_SRV_ACTION_USERS_REMOVE_REGISTRATIONS] = __("Remove registrations"),
  [NEW_SRV_ACTION_USERS_SET_PENDING] = __("Mark PENDING"),
  [NEW_SRV_ACTION_USERS_SET_OK] = __("Mark OK"),
  [NEW_SRV_ACTION_USERS_SET_REJECTED] = __("Mark REJECTED"),
  [NEW_SRV_ACTION_USERS_SET_INVISIBLE] = __("Mark INVISIBLE"),
  [NEW_SRV_ACTION_USERS_CLEAR_INVISIBLE] = __("Clear INVISIBLE"),
  [NEW_SRV_ACTION_USERS_SET_BANNED] = __("Mark BANNED"),
  [NEW_SRV_ACTION_USERS_CLEAR_BANNED] = __("Clear BANNED"),
  [NEW_SRV_ACTION_USERS_SET_LOCKED] = __("Mark LOCKED"),
  [NEW_SRV_ACTION_USERS_CLEAR_LOCKED] = __("Clear LOCKED"),
  [NEW_SRV_ACTION_USERS_ADD_BY_LOGIN] = __("Add by login"),
  [NEW_SRV_ACTION_USERS_ADD_BY_USER_ID] = __("Add by ID"),
  [NEW_SRV_ACTION_PRIV_USERS_REMOVE] = __("Remove"),
  [NEW_SRV_ACTION_PRIV_USERS_ADD_OBSERVER] = __("Add OBSERVER"),
  [NEW_SRV_ACTION_PRIV_USERS_DEL_OBSERVER] = __("Del OBSERVER"),
  [NEW_SRV_ACTION_PRIV_USERS_ADD_EXAMINER] = __("Add EXAMINER"),
  [NEW_SRV_ACTION_PRIV_USERS_DEL_EXAMINER] = __("Del EXAMINER"),
  [NEW_SRV_ACTION_PRIV_USERS_ADD_CHIEF_EXAMINER] = __("Add CHIEF EXAMINER"),
  [NEW_SRV_ACTION_PRIV_USERS_DEL_CHIEF_EXAMINER] = __("Del CHIEF EXAMINER"),
  [NEW_SRV_ACTION_PRIV_USERS_ADD_COORDINATOR] = __("Add COORDINATOR"),
  [NEW_SRV_ACTION_PRIV_USERS_DEL_COORDINATOR] = __("Del COORDINATOR"), 
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_LOGIN] = __("Add by login"),
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_USER_ID] = __("Add by ID"),
  [NEW_SRV_ACTION_START_CONTEST] = __("Start"),
  [NEW_SRV_ACTION_STOP_CONTEST] = __("Stop"),
  [NEW_SRV_ACTION_CONTINUE_CONTEST] = __("Continue"),
  [NEW_SRV_ACTION_SCHEDULE] = __("Reschedule"),
  [NEW_SRV_ACTION_CHANGE_DURATION] = __("Change duration"),
  [NEW_SRV_ACTION_SUBMIT_RUN] = __("Send!"),
  [NEW_SRV_ACTION_SUBMIT_CLAR] = __("Send!"),
  [NEW_SRV_ACTION_CHANGE_RUN_USER_ID] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_USER_LOGIN] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_PROB_ID] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_VARIANT] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_LANG_ID] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_IS_IMPORTED] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_IS_HIDDEN] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_IS_READONLY] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_STATUS] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_TEST] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_SCORE] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_SCORE_ADJ] = __("Change"),
  [NEW_SRV_ACTION_CHANGE_RUN_PAGES] = __("Change"),
  [NEW_SRV_ACTION_COMPARE_RUNS] = __("Compare"),
  [NEW_SRV_ACTION_UPLOAD_REPORT] = __("Upload!"),
  [NEW_SRV_ACTION_REJUDGE_PROBLEM_1] = __("Rejudge problem"),
  [NEW_SRV_ACTION_CLAR_REPLY] = __("Reply to sender"),
  [NEW_SRV_ACTION_CLAR_REPLY_ALL] = __("Reply to all"),
  [NEW_SRV_ACTION_CLAR_REPLY_READ_PROBLEM] = __("Read the problem"),
  [NEW_SRV_ACTION_CLAR_REPLY_NO_COMMENTS] = __("No comments"),
  [NEW_SRV_ACTION_CLAR_REPLY_YES] = __("Yes"),
  [NEW_SRV_ACTION_CLAR_REPLY_NO] = __("No"),
  [NEW_SRV_ACTION_REJUDGE_DISPLAYED_2] = __("Rejudge displayed runs!"),
  [NEW_SRV_ACTION_FULL_REJUDGE_DISPLAYED_2] = __("Fully rejudge displayed runs!"),
  [NEW_SRV_ACTION_REJUDGE_PROBLEM_2] = __("Rejudge problem!"),
  [NEW_SRV_ACTION_REJUDGE_SUSPENDED_2] = __("Judge suspended runs!"),
  [NEW_SRV_ACTION_REJUDGE_ALL_2] = __("Rejudge all!!!"),
  [NEW_SRV_ACTION_PRINT_RUN] = __("Print"),
  [NEW_SRV_ACTION_UPDATE_STANDINGS_2] = __("Update standings!"),
  [NEW_SRV_ACTION_RESET_2] = __("Reset the contest!!!"),
  [NEW_SRV_ACTION_GENERATE_PASSWORDS_2] = __("Generate random contest passwords!"),
  [NEW_SRV_ACTION_CLEAR_PASSWORDS_2] = __("Clear contest passwords!"),
  [NEW_SRV_ACTION_GENERATE_REG_PASSWORDS_2] = __("Generate random registration passwords!"),
  [NEW_SRV_ACTION_USER_CHANGE_STATUS] = __("Change status"),
  [NEW_SRV_ACTION_ISSUE_WARNING] = __("Issue warning"),
  [NEW_SRV_ACTION_NEW_RUN] = __("Add run"),
  [NEW_SRV_ACTION_FORGOT_PASSWORD_2] = __("Submit"),
  [NEW_SRV_ACTION_SUBMIT_APPEAL] = __("Submit appeal"),
  [NEW_SRV_ACTION_VIRTUAL_START] = __("Start virtual contest"),
  [NEW_SRV_ACTION_VIRTUAL_STOP] = __("Stop virtual contest"),
  [NEW_SRV_ACTION_DOWNLOAD_ARCHIVE_1] = __("Download archive of runs"),
  [NEW_SRV_ACTION_DOWNLOAD_ARCHIVE_2] = __("Download archive of runs"),
  [NEW_SRV_ACTION_UPLOAD_RUNLOG_CSV_1] = __("Add runs in CSV format"),
  [NEW_SRV_ACTION_UPLOAD_RUNLOG_CSV_2] = __("Add runs in CSV format!"),
  [NEW_SRV_ACTION_CLEAR_DISPLAYED_1] = __("Clear displayed runs"),
  [NEW_SRV_ACTION_CLEAR_DISPLAYED_2] = __("Clear displayed runs!"),
  [NEW_SRV_ACTION_IGNORE_DISPLAYED_1] = __("Ignore displayed runs"),
  [NEW_SRV_ACTION_IGNORE_DISPLAYED_2] = __("Ignore displayed runs!"),
  [NEW_SRV_ACTION_DISQUALIFY_DISPLAYED_1] = __("Disqualify displayed runs"),
  [NEW_SRV_ACTION_DISQUALIFY_DISPLAYED_2] = __("Disqualify displayed runs!"),
};

const int ns_priv_next_state[NEW_SRV_ACTION_LAST] =
{
  [NEW_SRV_ACTION_USERS_REMOVE_REGISTRATIONS] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_PENDING] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_OK] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_REJECTED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_INVISIBLE] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_INVISIBLE] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_BANNED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_BANNED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_LOCKED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_LOCKED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_ADD_BY_USER_ID] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_ADD_BY_LOGIN] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_PRIV_USERS_REMOVE] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_OBSERVER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_OBSERVER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_EXAMINER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_EXAMINER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_CHIEF_EXAMINER]=NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_CHIEF_EXAMINER]=NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_COORDINATOR] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_COORDINATOR] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_USER_ID] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_LOGIN] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_NEW_RUN] = NEW_SRV_ACTION_NEW_RUN_FORM,
  [NEW_SRV_ACTION_CHANGE_RUN_STATUS] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_USER_ID] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_USER_LOGIN] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_PROB_ID] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_VARIANT] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_LANG_ID] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_IS_IMPORTED] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_IS_HIDDEN] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_IS_READONLY] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_TEST] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_SCORE] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_SCORE_ADJ] = NEW_SRV_ACTION_VIEW_SOURCE,
  [NEW_SRV_ACTION_CHANGE_RUN_PAGES] = NEW_SRV_ACTION_VIEW_SOURCE,
};

/* previous state (return in case of error) */
const int ns_priv_prev_state[NEW_SRV_ACTION_LAST] =
{
  [NEW_SRV_ACTION_USERS_REMOVE_REGISTRATIONS] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_PENDING] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_OK] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_REJECTED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_INVISIBLE] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_INVISIBLE] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_BANNED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_BANNED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_SET_LOCKED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_CLEAR_LOCKED] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_ADD_BY_USER_ID] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_USERS_ADD_BY_LOGIN] = NEW_SRV_ACTION_VIEW_USERS,
  [NEW_SRV_ACTION_PRIV_USERS_REMOVE] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_OBSERVER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_OBSERVER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_EXAMINER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_EXAMINER] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_CHIEF_EXAMINER]=NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_CHIEF_EXAMINER]=NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_COORDINATOR] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_DEL_COORDINATOR] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_USER_ID] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
  [NEW_SRV_ACTION_PRIV_USERS_ADD_BY_LOGIN] = NEW_SRV_ACTION_PRIV_USERS_VIEW,
};

/* previous state (return in case of error) for unprivileged users */
const int ns_unpriv_prev_state[NEW_SRV_ACTION_LAST] =
{
};

/*
 * Local variables:
 *  compile-command: "make"
 *  c-font-lock-extra-types: ("\\sw+_t" "FILE" "va_list")
 * End:
 */
