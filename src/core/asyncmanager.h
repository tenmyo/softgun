/*-
 * Copyright 2017 TENMYO Masakazu. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

// Types
//   Handle_t
//      |-- StreamHandle_t
//      `-- PollHandle_t
typedef struct Handle_t Handle_t;
typedef struct StreamHandle_t StreamHandle_t;
typedef struct PollHandle_t PollHandle_t;
static inline Handle_t * AsyncManager_Stream2Handle(StreamHandle_t *stream) {
  return (Handle_t *)stream;
}
static inline Handle_t * AsyncManager_Poll2Handle(PollHandle_t *poll) {
  return (Handle_t *)poll;
}

// Handle
typedef void (*AsyncManager_close_cb)(Handle_t *handle, void *clientdata);
int AsyncManager_Close(Handle_t *handle, AsyncManager_close_cb close_cb, void *clientdata);
int AsyncManager_BufferSizeSend(Handle_t *handle, int *value);
int AsyncManager_BufferSizeRecv(Handle_t *handle, int *value);

// Stream
typedef void (*AsyncManager_connection_cb)(int status, StreamHandle_t *handle, const char *host, int port, void *clientdata);
typedef void (*AsyncManager_write_cb)(int status, StreamHandle_t *handle, void *clientdata);
typedef void (*AsyncManager_read_cb)(StreamHandle_t *handle, const void *buf, signed long len, void *clientdata);
int AsyncManager_Write(StreamHandle_t *handle, const void *base, size_t len, AsyncManager_write_cb write_cb, void *clientdata);
int AsyncManager_ReadStart(StreamHandle_t *handle, AsyncManager_read_cb read_cb, void *clientdata);
int AsyncManager_ReadStop(StreamHandle_t *handle);

// TCP
int AsyncManager_InitTcpServer(const char *ip, int port, int backlog, int nodelay, AsyncManager_connection_cb connection_cb, void *clientdata);

// Poll
enum {
  ASYNCMANAGER_EVENT_READABLE = 1<<0,
  ASYNCMANAGER_EVENT_WRITABLE = 1<<1,
};
typedef void (*AsyncManager_poll_cb)(PollHandle_t *handle, int status, int events, void *clientdata);
PollHandle_t * AsyncManager_PollInit(int fd);
int AsyncManager_PollStart(PollHandle_t *handle, int events, AsyncManager_poll_cb cb, void *clientdata);
int AsyncManager_PollStop(PollHandle_t *handle);

#ifdef __cplusplus
}
#endif