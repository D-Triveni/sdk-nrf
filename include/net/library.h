/* TODO: Handle other events */
#define WPA_SUPP_EVENTS (NET_EVENT_WPA_SUPP_READY) || (NET_EVENT_WPA_SUPP_NOT_READY)

typedef int (*start_app_callback_t)();
typedef int (*stop_app_callback_t)();

typedef struct {
    start_app_callback_t start_app;
    stop_app_callback_t stop_app;
} app_callbacks_t;

int register_events(app_callbacks_t cb);
