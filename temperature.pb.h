/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.7-dev at Wed Jun 22 16:57:50 2016. */

#ifndef PB_TEMPERATURE_PB_H_INCLUDED
#define PB_TEMPERATURE_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _temperature_Temperature {
    int64_t timestamp;
    float celsius;
/* @@protoc_insertion_point(struct:temperature_Temperature) */
} temperature_Temperature;

/* Default values for struct fields */

/* Initializer values for message structs */
#define temperature_Temperature_init_default     {0, 0}
#define temperature_Temperature_init_zero        {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define temperature_Temperature_timestamp_tag    1
#define temperature_Temperature_celsius_tag      2

/* Struct field encoding specification for nanopb */
extern const pb_field_t temperature_Temperature_fields[3];

/* Maximum encoded size of messages (where known) */
#define temperature_Temperature_size             16

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TEMPERATURE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
