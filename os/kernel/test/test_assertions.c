#include <check.h>
#include <stdlib.h>
#include <unistd.h>		/* unlink() */
#include "vm.h"
#include "action.h"
#include "test_util.h"

START_TEST(test_set_act_state_error)
{
    /* Pre: action list is initialized. */
    peos_action_t *actions = make_actions(10, ACT_NONE);
    
    /* Action/Post: assertion failure. */
    mark_point();
    fail_unless(set_act_state(NULL, ACT_READY, actions, 10) == -1, "error not detected");
    free_actions(actions, 10);
}
END_TEST

START_TEST(test_list_actions_error)
{
    peos_action_t *acts = 0;

    /* No process loaded. */
    /*  Pre: no actions. */
    peos_action_t *actions = NULL;

    /* Action. */
    mark_point();
    acts = peos_find_actions(ACT_READY, actions, 0);

    /* Post: assertion failure. */
    fail_unless(acts == NULL, "didn't return error code.");

}
END_TEST


int
main(int argc, char *argv[])
{
    int nf;
    SRunner *sr;
    TCase *tc;
    Suite *s = suite_create("action");

    parse_args(argc, argv);

    tc = tcase_create("assertions");
    suite_add_tcase(s, tc);
    tcase_add_test(tc, test_list_actions_error);
    tcase_add_test(tc, test_set_act_state_error);

    sr = srunner_create(s);

    srunner_set_fork_status(sr, fork_status);

    srunner_run_all(sr, verbosity);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    suite_free(s);
    return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}