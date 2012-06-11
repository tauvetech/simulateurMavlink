/** @file
 *	@brief MAVLink comm protocol testsuite generated from custom_mavlink_messages.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef CUSTOM_MAVLINK_MESSAGES_TESTSUITE_H
#define CUSTOM_MAVLINK_MESSAGES_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_custom_mavlink_messages(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_custom_mavlink_messages(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_resource_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_resource_status_t packet_in = {
		5,
	72,
	};
	mavlink_resource_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.resource = packet_in.resource;
        	packet1.status = packet_in.status;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_resource_status_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_resource_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_resource_status_pack(system_id, component_id, &msg , packet1.resource , packet1.status );
	mavlink_msg_resource_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_resource_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.resource , packet1.status );
	mavlink_msg_resource_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_resource_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_resource_status_send(MAVLINK_COMM_1 , packet1.resource , packet1.status );
	mavlink_msg_resource_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_request_resource_status_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_request_resource_status_list_t packet_in = {
		5,
	};
	mavlink_request_resource_status_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.target_system = packet_in.target_system;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_resource_status_list_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_request_resource_status_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_resource_status_list_pack(system_id, component_id, &msg , packet1.target_system );
	mavlink_msg_request_resource_status_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_resource_status_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system );
	mavlink_msg_request_resource_status_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_request_resource_status_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_resource_status_list_send(MAVLINK_COMM_1 , packet1.target_system );
	mavlink_msg_request_resource_status_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_service_availability(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_service_availability_t packet_in = {
		5,
	72,
	};
	mavlink_service_availability_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.service = packet_in.service;
        	packet1.availablility = packet_in.availablility;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_service_availability_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_service_availability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_service_availability_pack(system_id, component_id, &msg , packet1.service , packet1.availablility );
	mavlink_msg_service_availability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_service_availability_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.service , packet1.availablility );
	mavlink_msg_service_availability_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_service_availability_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_service_availability_send(MAVLINK_COMM_1 , packet1.service , packet1.availablility );
	mavlink_msg_service_availability_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_request_service_availability_list(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_request_service_availability_list_t packet_in = {
		5,
	};
	mavlink_request_service_availability_list_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.target_system = packet_in.target_system;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_service_availability_list_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_request_service_availability_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_service_availability_list_pack(system_id, component_id, &msg , packet1.target_system );
	mavlink_msg_request_service_availability_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_service_availability_list_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system );
	mavlink_msg_request_service_availability_list_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_request_service_availability_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_request_service_availability_list_send(MAVLINK_COMM_1 , packet1.target_system );
	mavlink_msg_request_service_availability_list_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_perform_service(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_perform_service_t packet_in = {
		17.0,
	45.0,
	73.0,
	41,
	108,
	};
	mavlink_perform_service_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.param_1 = packet_in.param_1;
        	packet1.param_2 = packet_in.param_2;
        	packet1.param_3 = packet_in.param_3;
        	packet1.target_system = packet_in.target_system;
        	packet1.action = packet_in.action;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_perform_service_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_perform_service_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_perform_service_pack(system_id, component_id, &msg , packet1.target_system , packet1.action , packet1.param_1 , packet1.param_2 , packet1.param_3 );
	mavlink_msg_perform_service_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_perform_service_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.action , packet1.param_1 , packet1.param_2 , packet1.param_3 );
	mavlink_msg_perform_service_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_perform_service_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_perform_service_send(MAVLINK_COMM_1 , packet1.target_system , packet1.action , packet1.param_1 , packet1.param_2 , packet1.param_3 );
	mavlink_msg_perform_service_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_custom_mavlink_messages(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_resource_status(system_id, component_id, last_msg);
	mavlink_test_request_resource_status_list(system_id, component_id, last_msg);
	mavlink_test_service_availability(system_id, component_id, last_msg);
	mavlink_test_request_service_availability_list(system_id, component_id, last_msg);
	mavlink_test_perform_service(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // CUSTOM_MAVLINK_MESSAGES_TESTSUITE_H
