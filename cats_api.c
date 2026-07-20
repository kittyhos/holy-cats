#include <microhttpd.h>
#include <string.h>

#define PORT 8080

const char *json_response =
"{"
"\"cats\": ["
"{\"id\":1,\"name\":\"Michi\",\"age\":2},"
"{\"id\":2,\"name\":\"Luna\",\"age\":4},"
"{\"id\":3,\"name\":\"Tom\",\"age\":1}"
"]"
"}";

static enum MHD_Result handler(
    void *cls,
    struct MHD_Connection *connection,
    const char *url,
    const char *method,
    const char *version,
    const char *upload_data,
    size_t *upload_data_size,
    void **con_cls)
{
    if (strcmp(method, "GET") != 0)
        return MHD_NO;

    if (strcmp(url, "/cats") == 0)
    {
        struct MHD_Response *response =
            MHD_create_response_from_buffer(
                strlen(json_response),
                (void *)json_response,
                MHD_RESPMEM_PERSISTENT);

        MHD_add_response_header(response, "Content-Type", "application/json");

        enum MHD_Result ret =
            MHD_queue_response(connection, MHD_HTTP_OK, response);

        MHD_destroy_response(response);
        return ret;
    }

    const char *not_found = "{\"error\":\"Not Found\"}";

    struct MHD_Response *response =
        MHD_create_response_from_buffer(
            strlen(not_found),
            (void *)not_found,
            MHD_RESPMEM_PERSISTENT);

    MHD_add_response_header(response, "Content-Type", "application/json");

    enum MHD_Result ret =
        MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);

    MHD_destroy_response(response);
    return ret;
}

int main()
{
    struct MHD_Daemon *daemon =
        MHD_start_daemon(
            MHD_USE_INTERNAL_POLLING_THREAD,
            PORT,
            NULL,
            NULL,
            &handler,
            NULL,
            MHD_OPTION_END);

    if (!daemon)
        return 1;

    printf("API de gatos ejecutándose en http://localhost:%d/cats\n", PORT);
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}
