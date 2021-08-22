#ifndef MIN_MAX_H
#define MIN_MAX_H

#ifdef __cplusplus
extern "C" {
#endif

#define NUMARGS(type, ...) \
	(sizeof((type[]){__VA_ARGS__}) / sizeof(type))

#define MAX(type, ...) \
	({ \
		type args[] = {__VA_ARGS__}; \
		int i; \
		for (i = 1; i < NUMARGS(type, __VA_ARGS__) - 1; \
			i++, args[0] = args[0] < args[i] ? args[i] : args[0]); \
		args[0]; \
	})
#define MIN(type, ...) \
	({ \
		type args[] = {__VA_ARGS__}; \
		int i; \
		for (i = 1; i < NUMARGS(type, __VA_ARGS__) - 1; \
			i++, args[0] = args[0] > args[i] ? args[i] : args[0]); \
		args[0]; \
	})
#define MAX_AMONG_TWO_NUM(a, b) \
	({ \
		__auto_type _a = (a); \
		__auto_type _b = (b); \
		_a > _b ? _a : _b; \
	})
#define MIN_AMONG_TWO_NUM(a, b) \
	({ \
		__auto_type _a = (a); \
		__auto_type _b = (b); \
		_a < _b ? _a : _b; \
	})

#ifdef __cplusplus
}
#endif

#endif /* not MIN_MAX_H */