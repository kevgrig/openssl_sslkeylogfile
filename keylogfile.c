#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <ssl/ssl_local.h>

static void keylog_callback(const SSL *ssl, const char *line) {
  fprintf(stderr, "%s\n", line);
}

SSL_CTX *SSL_CTX_new(const SSL_METHOD *meth) {
  SSL_CTX* (*real_SSL_CTX_new)(const SSL_METHOD *meth) = dlsym(RTLD_NEXT, "SSL_CTX_new");
  if (!real_SSL_CTX_new) {
    fprintf(stderr, "Could not find real SSL_CTX_new\n");
    exit(1);
  }
  #ifdef DEBUG
  fprintf(stderr, "Calling real SSL_CTX_new\n");
  #endif
  SSL_CTX *ctx = real_SSL_CTX_new(meth);
  if (ctx != NULL) {
    ctx->keylog_callback = keylog_callback;
    fprintf(stderr, "[%s:%d:%s] Set custom keylog_callback to %p\n", __FILE__, __LINE__, __func__, ctx->keylog_callback);
  }
  #ifdef DEBUG
  fprintf(stderr, "Return ctx %p\n", ctx);
  #endif
  return ctx;
}
