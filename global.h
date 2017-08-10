#ifdef GLOBAL_MAIN
#define GLOBAL
#define GLOBAL_VAL(X) = X
#else
#define GLOBAL extern
#define GLOBAL_VAL(X)
#endif

#include <ogg/ogg.h>

GLOBAL struct {
	enum {
		EDIT_NONE,
		EDIT_LIST,
		EDIT_WRITE,
		EDIT_APPEND,
	} edit;
	
	bool gain_fix;
	bool gain_relative;
	bool gain_not_zero;
	double gain_val;
	
	int info_gain;
	
	bool tag_ignore_picture;
	bool tag_escape;
	bool tag_raw;
	char *tag_filename;
	
	char *in, *out;
} O;

GLOBAL enum {
	OPUS_HEADER,
	OPUS_HEADER_BORDER,
	OPUS_COMMENT,
	OPUS_COMMENT_BORDER,
	OPUS_SOUND,
	OPUS_REMNANT,
} opst;


GLOBAL char *vendor;
GLOBAL char **tag_file, **tag_edit;
GLOBAL size_t tagnum_file, tagnum_edit;
GLOBAL char const *OpusHead GLOBAL_VAL("\x4f\x70\x75\x73\x48\x65\x61\x64"),
	*OpusTags GLOBAL_VAL("\x4f\x70\x75\x73\x54\x61\x67\x73"),
	*mbp GLOBAL_VAL("\x4d\x45\x54\x41\x44\x41\x54\x41\x5f\x42\x4c\x4f\x43\x4b\x5f\x50\x49\x43\x54\x55\x52\x45\x3d");
GLOBAL size_t const mbplen GLOBAL_VAL(23);

GLOBAL FILE *fpopus;
