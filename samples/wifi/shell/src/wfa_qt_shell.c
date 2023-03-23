#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include <zephyr/zephyr.h>
#include <zephyr/shell/shell.h>

static int cmd_wfa_qt_start(const struct shell *shell,
		size_t argc,
		const char *argv[])
{
	printf("arg0: %s\n", argv[0]);
	return qt_main(argc,
			argv);
}

SHELL_STATIC_SUBCMD_SET_CREATE(
		wfa_qt_cmds,
		SHELL_CMD(app,
			NULL,
			"\"Start C-APP\"",
			cmd_wfa_qt_start),
		SHELL_SUBCMD_SET_END
		);

/* "wfa_qt" shell tool for Wi-Fi alliance certification test */
SHELL_CMD_REGISTER(wfa_qt,
		&wfa_qt_cmds,
		"wfa_qt_commands (only for internal use)",
		NULL);
