#ifndef __RUN_ARGS_H
#define __RUN_ARGS_H

typedef enum 
{
	RF_MODE_INTERPRET = 1,
	RF_MODE_COMPILE = 2,
} RUN_FLAG;


extern RUN_FLAG arg_runmode;
extern char const *arg_filepath;

#define INTERPRET_FLAG "-interpret"
#define COMPILE_FLAG   "-compile"

void set_run_args(int argc, char const *argv[]);

void check_run_args(void);

#endif