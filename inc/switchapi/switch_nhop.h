/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _switch_nhop_h_
#define _switch_nhop_h_

#include "switch_base_types.h"
#include "switch_handle.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum switch_nhop_index_type_ {
    SWITCH_NHOP_INDEX_TYPE_NONE,
    SWITCH_NHOP_INDEX_TYPE_ONE_PATH,
    SWITCH_NHOP_INDEX_TYPE_ECMP
} switch_nhop_index_type_t;

/**
 Create a Nexthop
 @param device - device to program the nexthop
 @param intf_handle - Interface to be associated with the nexthop
*/
switch_handle_t switch_api_nhop_create(switch_device_t device, switch_handle_t intf_handle);

/**
 Delete a Nexthop
 @param device device on which to create nhop group
 @param nhop_handle - Handle that identifies nexthop uniquely
*/
switch_status_t switch_api_nhop_delete(switch_device_t device, switch_handle_t nhop_handle);

/**
 Create a ECMP Group
 @param device - device to create the ecmp group
*/
switch_handle_t switch_api_ecmp_create(switch_device_t device);

/**
 Delete a ECMP Group
 @param nhop_handle - Handle that identifies ECMP group uniquely
*/
switch_status_t switch_api_ecmp_delete(switch_device_t device, switch_handle_t nhop_handle);

/**
 Add nexthop member to ecmp group
 @param device - device to program the nexthop
 @param ecmp_handle - handle that identifies ECMP group uniquely
 @param nhop_handle - Nexthop to be added to the ECMP Group
*/
switch_status_t switch_api_ecmp_member_add(switch_device_t device, switch_handle_t ecmp_handle, switch_handle_t nhop_handle);

/**
 Delete nexthop member from ecmp group
 @param device - device to program the nexthop
 @param ecmp_handle - handle that identifies ECMP group uniquely
 @param nhop_handle - Nexthop to be deleted from the ECMP Group
*/
switch_status_t switch_api_ecmp_member_delete(switch_device_t device, switch_handle_t nhop_handle, switch_handle_t intf_handle);

/*
 Create ECMP Group along with the members.
 @param member_count - Number of nexthops
 @param nhop_handle - List of nexthops to be added to ECMP group
*/
switch_handle_t switch_api_ecmp_create_with_members(switch_device_t device, uint32_t member_count,
                                            switch_handle_t *intf_handle);
switch_status_t switch_api_nhop_print_all(void);

#ifdef __cplusplus
}
#endif

#endif
