#pragma once

#include "bclib/bstrlib.h"

typedef struct AudioInputCfg {
  int channels;
  int samplerate;
} AudioInputCfg;

typedef struct PureDataInputCfg {
  bstring patch_directory;
  bstring patch_file;
} PureDataInputCfg;

typedef struct EncoderInputCfg {
  double quality;
} EncoderInputCfg;

typedef struct BroadcastInputCfg {
  bstring host;
  int port;
  bstring source;
  bstring password;
  bstring mount;
  bstring name;
  bstring description;
  bstring genre;
  bstring url;
} BroadcastInputCfg;

typedef struct SystemInputCfg {
  int thread_sleep;
  int stats_interval;
  int max_push_messages;
} SystemInputCfg;

typedef struct RadioInputCfg {
  PureDataInputCfg puredata;
  AudioInputCfg audio;
  SystemInputCfg system;
  EncoderInputCfg encoder;
  BroadcastInputCfg broadcast;

} RadioInputCfg;

RadioInputCfg *read_config(char *config_path);

void destroy_config(RadioInputCfg *cfg);
