/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <assert.h>
#include "sysinit/sysinit.h"
#include "syscfg/syscfg.h"
#include "os/os_mempool.h"
#include "mem/mem.h"
#include "os_priv.h"

#if MYNEWT_VAL(MSYS_1_BLOCK_COUNT) > 0
#define SYSINIT_MSYS_1_MEMBLOCK_SIZE                \
    OS_ALIGN(MYNEWT_VAL(MSYS_1_BLOCK_SIZE), 4)
#define SYSINIT_MSYS_1_MEMPOOL_SIZE                 \
    OS_MEMPOOL_SIZE(MYNEWT_VAL(MSYS_1_BLOCK_COUNT),  \
                    SYSINIT_MSYS_1_MEMBLOCK_SIZE)
static os_membuf_t os_msys_init_1_data[SYSINIT_MSYS_1_MEMPOOL_SIZE];
static struct os_mbuf_pool os_msys_init_1_mbuf_pool;
static struct os_mempool os_msys_init_1_mempool;
#endif

#if MYNEWT_VAL(MSYS_2_BLOCK_COUNT) > 0
#define SYSINIT_MSYS_2_MEMBLOCK_SIZE                \
    OS_ALIGN(MYNEWT_VAL(MSYS_2_BLOCK_SIZE), 4)
#define SYSINIT_MSYS_2_MEMPOOL_SIZE                 \
    OS_MEMPOOL_SIZE(MYNEWT_VAL(MSYS_2_BLOCK_COUNT),  \
                    SYSINIT_MSYS_2_MEMBLOCK_SIZE)
static os_membuf_t os_msys_init_2_data[SYSINIT_MSYS_2_MEMPOOL_SIZE];
static struct os_mbuf_pool os_msys_init_2_mbuf_pool;
static struct os_mempool os_msys_init_2_mempool;
#endif

#if MYNEWT_VAL(MSYS_3_BLOCK_COUNT) > 0
#define SYSINIT_MSYS_3_MEMBLOCK_SIZE                \
    OS_ALIGN(MYNEWT_VAL(MSYS_3_BLOCK_SIZE), 4)
#define SYSINIT_MSYS_3_MEMPOOL_SIZE                 \
    OS_MEMPOOL_SIZE(MYNEWT_VAL(MSYS_3_BLOCK_COUNT),  \
                    SYSINIT_MSYS_3_MEMBLOCK_SIZE)
static os_membuf_t os_msys_init_3_data[SYSINIT_MSYS_3_MEMPOOL_SIZE];
static struct os_mbuf_pool os_msys_init_3_mbuf_pool;
static struct os_mempool os_msys_init_3_mempool;
#endif

#if MYNEWT_VAL(MSYS_4_BLOCK_COUNT) > 0
#define SYSINIT_MSYS_4_MEMBLOCK_SIZE                \
    OS_ALIGN(MYNEWT_VAL(MSYS_4_BLOCK_SIZE), 4)
#define SYSINIT_MSYS_4_MEMPOOL_SIZE                 \
    OS_MEMPOOL_SIZE(MYNEWT_VAL(MSYS_4_BLOCK_COUNT),  \
                    SYSINIT_MSYS_4_MEMBLOCK_SIZE)
static os_membuf_t os_msys_init_4_data[SYSINIT_MSYS_4_MEMPOOL_SIZE];
static struct os_mbuf_pool os_msys_init_4_mbuf_pool;
static struct os_mempool os_msys_init_4_mempool;
#endif

#if MYNEWT_VAL(MSYS_5_BLOCK_COUNT) > 0
#define SYSINIT_MSYS_5_MEMBLOCK_SIZE                \
    OS_ALIGN(MYNEWT_VAL(MSYS_5_BLOCK_SIZE), 4)
#define SYSINIT_MSYS_5_MEMPOOL_SIZE                 \
    OS_MEMPOOL_SIZE(MYNEWT_VAL(MSYS_5_BLOCK_COUNT),  \
                    SYSINIT_MSYS_5_MEMBLOCK_SIZE)

static os_membuf_t os_msys_init_5_data[SYSINIT_MSYS_5_MEMPOOL_SIZE];
static struct os_mbuf_pool os_msys_init_5_mbuf_pool;
static struct os_mempool os_msys_init_5_mempool;
#endif

static void
os_msys_init_once(void *data, struct os_mempool *mempool,
                  struct os_mbuf_pool *mbuf_pool,
                  int block_count, int block_size, char *name)
{
    int rc;

    rc = mem_init_mbuf_pool(data, mempool, mbuf_pool, block_count, block_size,
                            name);
    SYSINIT_PANIC_ASSERT(rc == 0);

    rc = os_msys_register(mbuf_pool);
    SYSINIT_PANIC_ASSERT(rc == 0);
}

void
os_msys_init(void)
{
    os_msys_reset();

#if MYNEWT_VAL(MSYS_1_BLOCK_COUNT) > 0
    os_msys_init_once(os_msys_init_1_data,
                      &os_msys_init_1_mempool,
                      &os_msys_init_1_mbuf_pool,
                      MYNEWT_VAL(MSYS_1_BLOCK_COUNT),
                      SYSINIT_MSYS_1_MEMBLOCK_SIZE,
                      "msys_1");
#endif

#if MYNEWT_VAL(MSYS_2_BLOCK_COUNT) > 0
    os_msys_init_once(os_msys_init_2_data,
                      &os_msys_init_2_mempool,
                      &os_msys_init_2_mbuf_pool,
                      MYNEWT_VAL(MSYS_2_BLOCK_COUNT),
                      SYSINIT_MSYS_2_MEMBLOCK_SIZE,
                      "msys_2");
#endif

#if MYNEWT_VAL(MSYS_3_BLOCK_COUNT) > 0
    os_msys_init_once(os_msys_init_3_data,
                      &os_msys_init_3_mempool,
                      &os_msys_init_3_mbuf_pool,
                      MYNEWT_VAL(MSYS_3_BLOCK_COUNT),
                      SYSINIT_MSYS_3_MEMBLOCK_SIZE,
                      "msys_3");
#endif

#if MYNEWT_VAL(MSYS_4_BLOCK_COUNT) > 0
    os_msys_init_once(os_msys_init_4_data,
                      &os_msys_init_4_mempool,
                      &os_msys_init_4_mbuf_pool,
                      MYNEWT_VAL(MSYS_4_BLOCK_COUNT),
                      SYSINIT_MSYS_4_MEMBLOCK_SIZE,
                      "msys_4");
#endif

#if MYNEWT_VAL(MSYS_5_BLOCK_COUNT) > 0
    os_msys_init_once(os_msys_init_5_data,
                      &os_msys_init_5_mempool,
                      &os_msys_init_5_mbuf_pool,
                      MYNEWT_VAL(MSYS_5_BLOCK_COUNT),
                      SYSINIT_MSYS_5_MEMBLOCK_SIZE,
                      "msys_5");
#endif
}
