
#ifndef ZCONTROLPLUGIN_EXPORT_H
#define ZCONTROLPLUGIN_EXPORT_H

#ifdef ZCONTROLPLUGIN_STATIC_DEFINE
#  define ZCONTROLPLUGIN_EXPORT
#  define ZCONTROLPLUGIN_NO_EXPORT
#else
#  ifndef ZCONTROLPLUGIN_EXPORT
#    ifdef ZControlplugin_EXPORTS
        /* We are building this library */
#      define ZCONTROLPLUGIN_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ZCONTROLPLUGIN_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ZCONTROLPLUGIN_NO_EXPORT
#    define ZCONTROLPLUGIN_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ZCONTROLPLUGIN_DEPRECATED
#  define ZCONTROLPLUGIN_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ZCONTROLPLUGIN_DEPRECATED_EXPORT
#  define ZCONTROLPLUGIN_DEPRECATED_EXPORT ZCONTROLPLUGIN_EXPORT ZCONTROLPLUGIN_DEPRECATED
#endif

#ifndef ZCONTROLPLUGIN_DEPRECATED_NO_EXPORT
#  define ZCONTROLPLUGIN_DEPRECATED_NO_EXPORT ZCONTROLPLUGIN_NO_EXPORT ZCONTROLPLUGIN_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ZCONTROLPLUGIN_NO_DEPRECATED
#    define ZCONTROLPLUGIN_NO_DEPRECATED
#  endif
#endif

#endif /* ZCONTROLPLUGIN_EXPORT_H */
