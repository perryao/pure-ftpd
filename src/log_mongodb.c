#include <config.h>

#ifdef WITH_MONGODB

#include "ftpd.h"
#include "log_mongodb_p.h"
#include "log_mongodb.h"

void pw_mongo_parse(const char * const file)
{
   printf("parse file!\n"); 
}

void pw_mongo_check(AuthResult * const result,
                    const char * account, const char * password,
                    const struct sockaddr_storage * const sa,
                    const struct sockaddr_storage * const peer)
{
    printf("check credentials\n");
}

void pw_mongo_exit(void)
{
    printf("exit\n");
}

#endif
