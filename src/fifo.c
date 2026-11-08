#include <FreeRTOS.h>
#include <queue.h>

#include "fifo.h"


void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id){

    struct request_msg message = {};

    xQueueReceive(requests, &message, portMAX_DELAY);

    message.output = message.input + 5;
    message.handled_by = id;

    // Send result
    xQueueSendToBack(results, &message, portMAX_DELAY);

}