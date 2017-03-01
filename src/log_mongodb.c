#include <config.h>

#ifdef WITH_MONGODB

#include "ftpd.h"
#include "parser.h"
#include "log_mongodb_p.h"
#include "log_mongodb.h"
#include "messages.h"
#include "crypto.h"
#include "crypto-sha1.h"
#include "alt_arc4random.h"
#include "utils.h"

#ifdef HAVE_LIBSODIUM
#include <sodium.h>
#endif

#ifdef WITH_DMALLOC
#include <dmalloc.h>
#endif

void pw_mongo_parse(const char * const file)
{
   printf("parse file!\n"); 
   if (generic_parser(file, mongodb_config_keywords) != 0) {
       die(421, LOG_ERR, "%s", file);
   }
   if (server == NULL) {
       die(421, LOG_ERR, MSG_SQL_MISSING_SERVER);
   }
}

static int pw_mongo_connect(mongoc_client_t ** const id_mongodb) 
{
    mongoc_database_t    *database;
    mongoc_collection_t  *collection;
    bson_t               *command,
                         reply;
    bson_error_t          error;
    bool                  retval;

    mongoc_init();

    *id_mongodb = NULL;
    *id_mongodb = mongoc_client_new("mongodb://localhost:27017");
    if (!id_mongodb) return 1;
    printf("created mongo client\n");
    /*
     * Do work. This example pings the database, prints the result as JSON and
     * performs an insert
     */
    command = BCON_NEW ("ping", BCON_INT32 (1));

    printf("about to execute command\n");
    retval = mongoc_client_command_simple (*id_mongodb, "admin", command, NULL, &reply, &error);

    if (!retval) {
        printf("%s\n", error.message);
        return 1;
    }
    return 0;
}

void pw_mongo_check(AuthResult * const result,
        const char * account, const char * password,
        const struct sockaddr_storage * const sa,
        const struct sockaddr_storage * const peer)
{
    mongoc_client_t *id_mongodb;
    result->auth_ok = 0; // 0 = failed
    if (pw_mongo_connect(&id_mongodb) != 0) {
        printf("failed to connect to mongo\n");
        goto bye;
    }
    result->auth_ok--; /* -1 */
    goto auth_ok;
    auth_ok:
    printf("auth_ok\n");
    result->dir = "/";
    result->auth_ok = -result->auth_ok;
    bye:
    printf("cleaning up\n");
    if (id_mongodb != NULL) {
        printf("destroying client\n");
        mongoc_client_destroy(id_mongodb);
    }
    mongoc_cleanup();
    printf("cleaned up\n");
}

void pw_mongo_exit(void)
{
    printf("exit\n");
}

#endif
