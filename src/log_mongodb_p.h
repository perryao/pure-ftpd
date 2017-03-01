#ifndef __LOG_MONGODB_P_H__
#define __LOG_MONGODB_P_H__ 1

#include <mongoc.h>
#include <bson.h>

static char *server;
static char *port;
static char *user;
static char *pw;
static char *db;
static char *collection;
static char *user_field;
static char *pass_field;
static char *uid_field;
static char *gid_field;
static char *dir_field;
static char *crypto;

static ConfigKeywords mongodb_config_keywords[] = {
    { "MONGODBServer", &server },
    { "MONGODBPort", &port },
    { "MONGODBUser", &user },
    { "MONGODBPassword", &pw },
    { "MONGODBDatabase", &db },
    { "MONGODBCollection", &collection },
    { "MONGODBUserField", &user_field },
    { "MONGODBPasswordField", &pass_field },
    { "MONGODBUIDField", &uid_field },
    { "MONGODBGIDField", &gid_field },
    { "MONGODBDirField", &dir_field },
    { "MONGODBCrypt", &crypto },
    { NULL, NULL }
};

#endif
