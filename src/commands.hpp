#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <cstdio>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#include "membrane.hpp"

void cmd_rm(std::vector<std::string>);
void cmd_rmdir(std::vector<std::string>);
void cmd_mkdir(std::vector<std::string>);
void cmd_exec(std::vector<std::string>);
void cmd_cd(std::vector<std::string>);
void cmd_touch(std::vector<std::string>);
void cmd_chmod(std::vector<std::string>);
void cmd_chroot(std::vector<std::string>);

void cmd_shell();
void cmd_pwd();
void cmd_whoami();
void cmd_hostname();
void cmd_getuid();
void cmd_getpid();
void cmd_getgid();

static std::map<std::string, std::function<void(std::vector<std::string>)>> passCmds = {
    {"rm", cmd_rm}, {"rmdir", cmd_rmdir}, {"mkdir", cmd_mkdir}, {"exec", cmd_exec},
    {"cd", cmd_cd}, {"touch", cmd_touch}, {"chmod", cmd_chmod}, {"chroot", cmd_chroot}
};

static std::map<std::string, std::function<void()>> nopassCmds = {
    {"shell", cmd_shell}, {"pwd", cmd_pwd}, {"whoami", cmd_whoami}, {"hostname", cmd_hostname},
    {"getuid", cmd_getuid}, {"getpid", cmd_getpid}, {"getgid", cmd_getgid}
};

#endif // _COMMANDS_HPP_
