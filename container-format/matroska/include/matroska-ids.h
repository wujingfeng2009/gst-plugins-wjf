/* 
 * (c) 2012
 *
 */
 

#ifndef _H_MATROSKA_IDS_H__
#define _H_MATROSKA_IDS_H__


/* 
 * Global defines
 */

/* Unknown size (all bits set to 1) */
#define MTRSK_EBML_SIZE_UNKNOWN          G_GINT64_CONSTANT(0x00ffffffffffffff)

/* EbmlDate offset from the unix epoch in seconds, 2001/01/01 00:00:00 UTC */
#define MTRSK_EBML_DATE_OFFSET           978307200


/* 
 * EBML version supported 
 */
 
#define MTRSK_EBML_VERSION 1


/* 
 * General EBML type ids 
 */
 
#define MTRSK_EBML_ID_VOID               0xEC
#define MTRSK_EBML_ID_CRC32              0xBF


/* 
 * Top level EBML ids
 */
 
/* Header master-ID */
#define MTRSK_EBML_ID_HEADER             0x1A45DFA3

/* Segment master-ID */
#define MTRSK_EBML_ID_SEGMENT                    0x18538067


/* 
 * IDs in the Header master 
 */
 
#define MTRSK_EBML_ID_EBMLVERSION        0x4286
#define MTRSK_EBML_ID_EBMLREADVERSION    0x42F7
#define MTRSK_EBML_ID_EBMLMAXIDLENGTH    0x42F2
#define MTRSK_EBML_ID_EBMLMAXSIZELENGTH  0x42F3
#define MTRSK_EBML_ID_DOCTYPE            0x4282
#define MTRSK_EBML_ID_DOCTYPEVERSION     0x4287
#define MTRSK_EBML_ID_DOCTYPEREADVERSION 0x4285

/* EBML DocType */
#define MTRSK_DOCTYPE_MATROSKA              "matroska"
#define MTRSK_DOCTYPE_WEBM                  "webm"


/* 
 * IDs in the Segment master 
 */
 
 /* Matroska element IDs. max. 32-bit */
#define MTRSK_ID_SEGMENTINFO                0x1549A966
#define MTRSK_ID_TRACKS                     0x1654AE6B
#define MTRSK_ID_CUES                       0x1C53BB6B
#define MTRSK_ID_TAGS                       0x1254C367
#define MTRSK_ID_SEEKHEAD                   0x114D9B74
#define MTRSK_ID_CLUSTER                    0x1F43B675
#define MTRSK_ID_ATTACHMENTS                0x1941A469
#define MTRSK_ID_CHAPTERS                   0x1043A770

/* IDs in the SegmentInfo master */
#define MTRSK_ID_TIMECODESCALE              0x2AD7B1
#define MTRSK_ID_DURATION                   0x4489
#define MTRSK_ID_WRITINGAPP                 0x5741
#define MTRSK_ID_MUXINGAPP                  0x4D80
#define MTRSK_ID_DATEUTC                    0x4461
#define MTRSK_ID_SEGMENTUID                 0x73A4
#define MTRSK_ID_SEGMENTFILENAME            0x7384
#define MTRSK_ID_PREVUID                    0x3CB923
#define MTRSK_ID_PREVFILENAME               0x3C83AB
#define MTRSK_ID_NEXTUID                    0x3EB923
#define MTRSK_ID_NEXTFILENAME               0x3E83BB
#define MTRSK_ID_TITLE                      0x7BA9
#define MTRSK_ID_SEGMENTFAMILY              0x4444
#define MTRSK_ID_CHAPTERTRANSLATE           0x6924

/* IDs in the ChapterTranslate master */
#define MTRSK_ID_CHAPTERTRANSLATEEDITIONUID 0x69FC
#define MTRSK_ID_CHAPTERTRANSLATECODEC      0x69BF
#define MTRSK_ID_CHAPTERTRANSLATEID         0x69A5

/* ID in the Tracks master */
#define MTRSK_ID_TRACKENTRY                 0xAE

/* IDs in the TrackEntry master */
#define MTRSK_ID_TRACKNUMBER                0xD7
#define MTRSK_ID_TRACKUID                   0x73C5
#define MTRSK_ID_TRACKTYPE                  0x83
#define MTRSK_ID_TRACKAUDIO                 0xE1
#define MTRSK_ID_TRACKVIDEO                 0xE0
#define MTRSK_ID_CONTENTENCODINGS           0x6D80
#define MTRSK_ID_CODECID                    0x86
#define MTRSK_ID_CODECPRIVATE               0x63A2
#define MTRSK_ID_CODECNAME                  0x258688
#define MTRSK_ID_TRACKNAME                  0x536E
#define MTRSK_ID_TRACKLANGUAGE              0x22B59C
#define MTRSK_ID_TRACKFLAGENABLED           0xB9
#define MTRSK_ID_TRACKFLAGDEFAULT           0x88
#define MTRSK_ID_TRACKFLAGFORCED            0x55AA
#define MTRSK_ID_TRACKFLAGLACING            0x9C
#define MTRSK_ID_TRACKMINCACHE              0x6DE7
#define MTRSK_ID_TRACKMAXCACHE              0x6DF8
#define MTRSK_ID_TRACKDEFAULTDURATION       0x23E383
#define MTRSK_ID_TRACKTIMECODESCALE         0x23314F
#define MTRSK_ID_MAXBLOCKADDITIONID         0x55EE
#define MTRSK_ID_TRACKATTACHMENTLINK        0x7446
#define MTRSK_ID_TRACKOVERLAY               0x6FAB
#define MTRSK_ID_TRACKTRANSLATE             0x6624
/* semi-draft */
#define MTRSK_ID_TRACKOFFSET                0x537F
/* semi-draft */
#define MTRSK_ID_CODECSETTINGS              0x3A9697
/* semi-draft */
#define MTRSK_ID_CODECINFOURL               0x3B4040
/* semi-draft */
#define MTRSK_ID_CODECDOWNLOADURL           0x26B240
/* semi-draft */
#define MTRSK_ID_CODECDECODEALL             0xAA

/* IDs in the TrackTranslate master */
#define MTRSK_ID_TRACKTRANSLATEEDITIONUID   0x66FC
#define MTRSK_ID_TRACKTRANSLATECODEC        0x66BF
#define MTRSK_ID_TRACKTRANSLATETRACKID      0x66A5

/* IDs in the TrackVideo master */
/* NOTE: This one is here only for backward compatibility.
 * Use _TRACKDEFAULDURATION */
#define MTRSK_ID_VIDEOFRAMERATE             0x2383E3
#define MTRSK_ID_VIDEODISPLAYWIDTH          0x54B0
#define MTRSK_ID_VIDEODISPLAYHEIGHT         0x54BA
#define MTRSK_ID_VIDEODISPLAYUNIT           0x54B2
#define MTRSK_ID_VIDEOPIXELWIDTH            0xB0
#define MTRSK_ID_VIDEOPIXELHEIGHT           0xBA
#define MTRSK_ID_VIDEOPIXELCROPBOTTOM       0x54AA
#define MTRSK_ID_VIDEOPIXELCROPTOP          0x54BB
#define MTRSK_ID_VIDEOPIXELCROPLEFT         0x54CC
#define MTRSK_ID_VIDEOPIXELCROPRIGHT        0x54DD
#define MTRSK_ID_VIDEOFLAGINTERLACED        0x9A
/* semi-draft */
#define MTRSK_ID_VIDEOSTEREOMODE            0x53B8
#define MTRSK_ID_VIDEOASPECTRATIOTYPE       0x54B3
#define MTRSK_ID_VIDEOCOLOURSPACE           0x2EB524
/* semi-draft */
#define MTRSK_ID_VIDEOGAMMAVALUE            0x2FB523

/* IDs in the TrackAudio master */
#define MTRSK_ID_AUDIOSAMPLINGFREQ          0xB5
#define MTRSK_ID_AUDIOBITDEPTH              0x6264
#define MTRSK_ID_AUDIOCHANNELS              0x9F
/* semi-draft */
#define MTRSK_ID_AUDIOCHANNELPOSITIONS      0x7D7B
#define MTRSK_ID_AUDIOOUTPUTSAMPLINGFREQ    0x78B5

/* IDs in the TrackContentEncoding master */
#define MTRSK_ID_CONTENTENCODING            0x6240

/* IDs in the ContentEncoding master */
#define MTRSK_ID_CONTENTENCODINGORDER       0x5031
#define MTRSK_ID_CONTENTENCODINGSCOPE       0x5032
#define MTRSK_ID_CONTENTENCODINGTYPE        0x5033
#define MTRSK_ID_CONTENTCOMPRESSION         0x5034
#define MTRSK_ID_CONTENTENCRYPTION          0x5035

/* IDs in the ContentCompression master */
#define MTRSK_ID_CONTENTCOMPALGO            0x4254
#define MTRSK_ID_CONTENTCOMPSETTINGS        0x4255

/* IDs in the ContentEncryption master */
#define MTRSK_ID_CONTENTENCALGO             0x47E1
#define MTRSK_ID_CONTENTENCKEYID            0x47E2
#define MTRSK_ID_CONTENTSIGNATURE           0x47E3
#define MTRSK_ID_CONTENTSIGKEYID            0x47E4
#define MTRSK_ID_CONTENTSIGALGO             0x47E5
#define MTRSK_ID_CONTENTSIGHASHALGO         0x47E6

/* ID in the CUEs master */
#define MTRSK_ID_POINTENTRY                 0xBB

/* IDs in the pointentry master */
#define MTRSK_ID_CUETIME                    0xB3
#define MTRSK_ID_CUETRACKPOSITIONS          0xB7

/* IDs in the CueTrackPositions master */
#define MTRSK_ID_CUETRACK                   0xF7
#define MTRSK_ID_CUECLUSTERPOSITION         0xF1
#define MTRSK_ID_CUEBLOCKNUMBER             0x5378
/* semi-draft */
#define MTRSK_ID_CUECODECSTATE              0xEA
/* semi-draft */
#define MTRSK_ID_CUEREFERENCE               0xDB

/* IDs in the CueReference master */
/* semi-draft */
#define MTRSK_ID_CUEREFTIME                 0x96
/* semi-draft */
#define MTRSK_ID_CUEREFCLUSTER              0x97
/* semi-draft */
#define MTRSK_ID_CUEREFNUMBER               0x535F
/* semi-draft */
#define MTRSK_ID_CUEREFCODECSTATE           0xEB

/* IDs in the Tags master */
#define MTRSK_ID_TAG                        0x7373

/* IDs in the Tag master */
#define MTRSK_ID_SIMPLETAG                  0x67C8
#define MTRSK_ID_TARGETS                    0x63C0

/* IDs in the SimpleTag master */
#define MTRSK_ID_TAGNAME                    0x45A3
#define MTRSK_ID_TAGSTRING                  0x4487
#define MTRSK_ID_TAGLANGUAGE                0x447A
#define MTRSK_ID_TAGDEFAULT                 0x4484
#define MTRSK_ID_TAGBINARY                  0x4485

/* IDs in the Targets master */
#define MTRSK_ID_TARGETTYPEVALUE            0x68CA
#define MTRSK_ID_TARGETTYPE                 0x63CA
#define MTRSK_ID_TARGETTRACKUID             0x63C5
#define MTRSK_ID_TARGETEDITIONUID           0x63C5
#define MTRSK_ID_TARGETCHAPTERUID           0x63C4
#define MTRSK_ID_TARGETATTACHMENTUID        0x63C6

/* IDs in the SeekHead master */
#define MTRSK_ID_SEEKENTRY                  0x4DBB

/* IDs in the SeekEntry master */
#define MTRSK_ID_SEEKID                     0x53AB
#define MTRSK_ID_SEEKPOSITION               0x53AC

/* IDs in the Cluster master */
#define MTRSK_ID_CLUSTERTIMECODE            0xE7
#define MTRSK_ID_BLOCKGROUP                 0xA0
#define MTRSK_ID_SIMPLEBLOCK                0xA3
#define MTRSK_ID_REFERENCEBLOCK             0xFB
#define MTRSK_ID_POSITION                   0xA7
#define MTRSK_ID_PREVSIZE                   0xAB
/* semi-draft */
#define MTRSK_ID_ENCRYPTEDBLOCK             0xAF
#define MTRSK_ID_SILENTTRACKS               0x5854

/* IDs in the SilentTracks master */
#define MTRSK_ID_SILENTTRACKNUMBER          0x58D7

/* IDs in the BlockGroup master */
#define MTRSK_ID_BLOCK                      0xA1
#define MTRSK_ID_BLOCKDURATION              0x9B
/* semi-draft */
#define MTRSK_ID_BLOCKVIRTUAL               0xA2
#define MTRSK_ID_REFERENCEBLOCK             0xFB
#define MTRSK_ID_BLOCKADDITIONS             0x75A1
#define MTRSK_ID_REFERENCEPRIORITY          0xFA
/* semi-draft */
#define MTRSK_ID_REFERENCEVIRTUAL           0xFD
/* semi-draft */
#define MTRSK_ID_CODECSTATE                 0xA4
#define MTRSK_ID_SLICES                     0x8E

/* IDs in the BlockAdditions master */
#define MTRSK_ID_BLOCKMORE                  0xA6

/* IDs in the BlockMore master */
#define MTRSK_ID_BLOCKADDID                 0xEE
#define MTRSK_ID_BLOCKADDITIONAL            0xA5

/* IDs in the Slices master */
#define MTRSK_ID_TIMESLICE                  0xE8

/* IDs in the TimeSlice master */
#define MTRSK_ID_LACENUMBER                 0xCC
/* semi-draft */
#define MTRSK_ID_FRAMENUMBER                0xCD
/* semi-draft */
#define MTRSK_ID_BLOCKADDITIONID            0xCB
/* semi-draft */
#define MTRSK_ID_TIMESLICEDELAY             0xCE
#define MTRSK_ID_TIMESLICEDURATION          0xCF

/* IDs in the Attachments master */
#define MTRSK_ID_ATTACHEDFILE               0x61A7

/* IDs in the AttachedFile master */
#define MTRSK_ID_FILEDESCRIPTION            0x467E
#define MTRSK_ID_FILENAME                   0x466E
#define MTRSK_ID_FILEMIMETYPE               0x4660
#define MTRSK_ID_FILEDATA                   0x465C
#define MTRSK_ID_FILEUID                    0x46AE
/* semi-draft */
#define MTRSK_ID_FILEREFERRAL               0x4675

/* IDs in the Chapters master */
#define MTRSK_ID_EDITIONENTRY               0x45B9

/* IDs in the EditionEntry master */
#define MTRSK_ID_EDITIONUID                 0x45BC
#define MTRSK_ID_EDITIONFLAGHIDDEN          0x45BD
#define MTRSK_ID_EDITIONFLAGDEFAULT         0x45DB
#define MTRSK_ID_EDITIONFLAGORDERED         0x45DD
#define MTRSK_ID_CHAPTERATOM                0xB6

/* IDs in the ChapterAtom master */
#define MTRSK_ID_CHAPTERUID                 0x73C4
#define MTRSK_ID_CHAPTERTIMESTART           0x91
#define MTRSK_ID_CHAPTERTIMESTOP            0x92
#define MTRSK_ID_CHAPTERFLAGHIDDEN          0x98
#define MTRSK_ID_CHAPTERFLAGENABLED         0x4598
#define MTRSK_ID_CHAPTERSEGMENTUID          0x6E67
#define MTRSK_ID_CHAPTERSEGMENTEDITIONUID   0x6EBC
#define MTRSK_ID_CHAPTERPHYSICALEQUIV       0x63C3
#define MTRSK_ID_CHAPTERTRACK               0x8F
#define MTRSK_ID_CHAPTERDISPLAY             0x80
#define MTRSK_ID_CHAPPROCESS                0x6944

/* IDs in the ChapProcess master */
#define MTRSK_ID_CHAPPROCESSCODECID         0x6955
#define MTRSK_ID_CHAPPROCESSPRIVATE         0x450D
#define MTRSK_ID_CHAPPROCESSCOMMAND         0x6911

/* IDs in the ChapProcessCommand master */
#define MTRSK_ID_CHAPPROCESSTIME            0x6922
#define MTRSK_ID_CHAPPROCESSDATA            0x6933

/* IDs in the ChapterDisplay master */
#define MTRSK_ID_CHAPSTRING                 0x85
#define MTRSK_ID_CHAPLANGUAGE               0x437C
#define MTRSK_ID_CHAPCOUNTRY                0x437E

/* IDs in the ChapterTrack master */
#define MTRSK_ID_CHAPTERTRACKNUMBER         0x89


/*
 * Matroska Codec IDs. Strings.
 */

#define MTRSK_CODEC_ID_VIDEO_VFW_FOURCC   "V_MS/VFW/FOURCC"
#define MTRSK_CODEC_ID_VIDEO_UNCOMPRESSED "V_UNCOMPRESSED"
#define MTRSK_CODEC_ID_VIDEO_MPEG4_SP     "V_MPEG4/ISO/SP"
#define MTRSK_CODEC_ID_VIDEO_MPEG4_ASP    "V_MPEG4/ISO/ASP"
#define MTRSK_CODEC_ID_VIDEO_MPEG4_AP     "V_MPEG4/ISO/AP"
#define MTRSK_CODEC_ID_VIDEO_MPEG4_AVC    "V_MPEG4/ISO/AVC"
#define MTRSK_CODEC_ID_VIDEO_MSMPEG4V3    "V_MPEG4/MS/V3"
#define MTRSK_CODEC_ID_VIDEO_MPEG1        "V_MPEG1"
#define MTRSK_CODEC_ID_VIDEO_MPEG2        "V_MPEG2"
/* FIXME: not (yet) in the spec! */
#define MTRSK_CODEC_ID_VIDEO_MJPEG        "V_MJPEG"
#define MTRSK_CODEC_ID_VIDEO_REALVIDEO1   "V_REAL/RV10"
#define MTRSK_CODEC_ID_VIDEO_REALVIDEO2   "V_REAL/RV20"
#define MTRSK_CODEC_ID_VIDEO_REALVIDEO3   "V_REAL/RV30"
#define MTRSK_CODEC_ID_VIDEO_REALVIDEO4   "V_REAL/RV40"
#define MTRSK_CODEC_ID_VIDEO_THEORA       "V_THEORA"
#define MTRSK_CODEC_ID_VIDEO_QUICKTIME    "V_QUICKTIME"
#define MTRSK_CODEC_ID_VIDEO_SNOW         "V_SNOW"
#define MTRSK_CODEC_ID_VIDEO_DIRAC        "V_DIRAC"
#define MTRSK_CODEC_ID_VIDEO_VP8          "V_VP8"

#define MTRSK_CODEC_ID_AUDIO_MPEG1_L1       "A_MPEG/L1"
#define MTRSK_CODEC_ID_AUDIO_MPEG1_L2       "A_MPEG/L2"
#define MTRSK_CODEC_ID_AUDIO_MPEG1_L3       "A_MPEG/L3"
#define MTRSK_CODEC_ID_AUDIO_PCM_INT_BE     "A_PCM/INT/BIG"
#define MTRSK_CODEC_ID_AUDIO_PCM_INT_LE     "A_PCM/INT/LIT"
#define MTRSK_CODEC_ID_AUDIO_PCM_FLOAT      "A_PCM/FLOAT/IEEE"
#define MTRSK_CODEC_ID_AUDIO_AC3            "A_AC3"
#define MTRSK_CODEC_ID_AUDIO_AC3_BSID9      "A_AC3/BSID9"
#define MTRSK_CODEC_ID_AUDIO_AC3_BSID10     "A_AC3/BSID10"
#define MTRSK_CODEC_ID_AUDIO_EAC3           "A_EAC3"
#define MTRSK_CODEC_ID_AUDIO_DTS            "A_DTS"
#define MTRSK_CODEC_ID_AUDIO_VORBIS         "A_VORBIS"
#define MTRSK_CODEC_ID_AUDIO_FLAC           "A_FLAC"
/* FIXME: not yet in the spec */
#define MTRSK_CODEC_ID_AUDIO_SPEEX          "A_SPEEX"
#define MTRSK_CODEC_ID_AUDIO_ACM            "A_MS/ACM"
#define MTRSK_CODEC_ID_AUDIO_TTA            "A_TTA1"
#define MTRSK_CODEC_ID_AUDIO_WAVPACK4       "A_WAVPACK4"
#define MTRSK_CODEC_ID_AUDIO_REAL_14_4      "A_REAL/14_4"
#define MTRSK_CODEC_ID_AUDIO_REAL_28_8      "A_REAL/28_8"
#define MTRSK_CODEC_ID_AUDIO_REAL_COOK      "A_REAL/COOK"
#define MTRSK_CODEC_ID_AUDIO_REAL_SIPR      "A_REAL/SIPR"
#define MTRSK_CODEC_ID_AUDIO_REAL_RALF      "A_REAL/RALF"
#define MTRSK_CODEC_ID_AUDIO_REAL_ATRC      "A_REAL/ATRC"
#define MTRSK_CODEC_ID_AUDIO_AAC            "A_AAC"
#define MTRSK_CODEC_ID_AUDIO_AAC_MPEG2      "A_AAC/MPEG2/"
#define MTRSK_CODEC_ID_AUDIO_AAC_MPEG4      "A_AAC/MPEG4/"
#define MTRSK_CODEC_ID_AUDIO_QUICKTIME_QDMC "A_QUICKTIME/QDMC"
#define MTRSK_CODEC_ID_AUDIO_QUICKTIME_QDM2 "A_QUICKTIME/QDM2"
/* Undefined for now:
#define MTRSK_CODEC_ID_AUDIO_MPC            "A_MPC"
*/

#define MTRSK_CODEC_ID_SUBTITLE_ASCII     "S_TEXT/ASCII"
#define MTRSK_CODEC_ID_SUBTITLE_UTF8      "S_TEXT/UTF8"
#define MTRSK_CODEC_ID_SUBTITLE_SSA       "S_TEXT/SSA"
#define MTRSK_CODEC_ID_SUBTITLE_ASS       "S_TEXT/ASS" 
#define MTRSK_CODEC_ID_SUBTITLE_USF       "S_TEXT/USF"
#define MTRSK_CODEC_ID_SUBTITLE_VOBSUB    "S_VOBSUB"
#define MTRSK_CODEC_ID_SUBTITLE_HDMVPGS   "S_HDMV/PGS"
#define MTRSK_CODEC_ID_SUBTITLE_BMP       "S_IMAGE/BMP"
#define MTRSK_CODEC_ID_SUBTITLE_KATE      "S_KATE"


/*
 * Matroska tags. Strings.
 */

#define MTRSK_TAG_ID_TITLE    "TITLE"
#define MTRSK_TAG_ID_AUTHOR   "AUTHOR"
#define MTRSK_TAG_ID_ARTIST   "ARTIST"
#define MTRSK_TAG_ID_ALBUM    "ALBUM"
#define MTRSK_TAG_ID_COMMENTS "COMMENTS"
#define MTRSK_TAG_ID_BITSPS   "BITSPS"
#define MTRSK_TAG_ID_BPS      "BPS"
#define MTRSK_TAG_ID_ENCODER  "ENCODER"
#define MTRSK_TAG_ID_DATE     "DATE"
#define MTRSK_TAG_ID_ISRC     "ISRC"
#define MTRSK_TAG_ID_COPYRIGHT "COPYRIGHT"
#define MTRSK_TAG_ID_BPM       "BPM"
#define MTRSK_TAG_ID_TERMS_OF_USE "TERMS_OF_USE"
#define MTRSK_TAG_ID_DATE      "DATE"
#define MTRSK_TAG_ID_COMPOSER  "COMPOSER"
#define MTRSK_TAG_ID_LEAD_PERFORMER  "LEAD_PERFOMER"
#define MTRSK_TAG_ID_GENRE     "GENRE"

#endif /* _H_MATROSKA_IDS_H__ */

