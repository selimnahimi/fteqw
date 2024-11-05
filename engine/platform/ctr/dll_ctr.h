#ifndef DLL_CTR_H
#define DLL_CTR_H

// cant include common.h here, good for now
#ifndef Q_strncmp
#define Q_strncmp(s1, s2, n) strncmp((s1), (s2), (n))
#endif
#ifndef Q_strcmp
#define Q_strcmp(s1, s2) strcmp((s1), (s2))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define RTLD_LAZY 0x0001
#define RTLD_NOW  0x0002

typedef struct dllexport_s
{
	const char *name;
	void *func;
} dllexport_t;

typedef struct Dl_info_s
{
	void *dli_fhandle;
	const char *dli_sname;
	const void *dli_saddr;
} Dl_info;

void *dlsym(void *handle, const char *symbol );
void *dlopen(const char *name, int flag );
int dlclose(void *handle);
char *dlerror( void );
int dladdr( const void *addr, Dl_info *info );

int dll_register( const char *name, dllexport_t *exports );

#ifdef __cplusplus
}
#endif

#endif
