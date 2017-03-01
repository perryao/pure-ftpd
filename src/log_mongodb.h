#ifndef __LOG_MONGODB_H__
#define __LOG_MONGODB_H__ 1

#define PASSWD_MONGO_ARGON2I "argon2i"
#define PASSWD_MONGO_SCRYPT "scrypt"
#define PASSWD_MONGO_CRYPT "crypt"
#define PASSWD_MONGO_CLEARTEXT "cleartext"
#define PASSWD_MONGO "password"
#define PASSWD_MONGO_MD5 "md5"
#define PASSWD_MONGO_SHA1 "sha1"
#define PASSWD_MONGO_ANY "any"
#define MONGO_DEFAULT_SERVER "localhost"
#define MONGO_DEFAULT_PORT 27017

void pw_mongo_parse(const char * const file);

void pw_mongo_check(AuthResult * const result,
                    const char * account, const char * password,
                    const struct sockaddr_storage * const sa,
                    const struct sockaddr_storage * const peer);

void pw_mongo_exit(void);
#endif
