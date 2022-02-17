/*
 * Copyright (c) 2020-2021. xxxxxx Software Ltd. All rights reserved.
 *
 * Author:     xxxxxx <xxxxxx@163.com>
 *
 * Maintainer: xxxxxx <xxxxxx@163.com>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// #include <glib.h>
#include <dbus/dbus.h>
// #include <stdbool.h>
// #include <unistd.h>
#include <stdio.h>
// #include <stdlib.h>
// #include <dbus/dbus-glib.h>

#include <iostream>
using namespace std;

static int method_get(DBusConnection *dbconn, const char *param)
{
    DBusMessage *msg;
    // DBusMessageIter arg;
    // DBusPendingCall *pending;
    DBusMessage *reply;
    int result = 0;
    DBusError dberr;

    dbus_error_init(&dberr);
    // https://dbus.freedesktop.org/doc/api/html/group__DBusMessage.html
    // DBusMessage * 	dbus_message_new_method_call (const char *destination, const char *path, const char *iface,
    // const char *method)
    msg = dbus_message_new_method_call("com.deepin.linglong.AppManager", "/com/deepin/linglong/PackageManager",
                                       "com.deepin.linglong.PackageManager", "test");
    if (msg == NULL) {
        printf("Message NULL\n");
        return -1;
    }

    dbus_message_append_args(msg, DBUS_TYPE_STRING, &param);
    reply = dbus_connection_send_with_reply_and_block(dbconn, msg, -1, &dberr);
    if (!reply) {
        printf("couldn't send message: %s\n", dberr.message);
    }

    dbus_message_unref(msg);
    char *retMsg;
    if (!dbus_message_get_args(reply, &dberr, DBUS_TYPE_STRING, &retMsg, DBUS_TYPE_INVALID)) {
        result = -1;
    }
    printf("dbus_message_new_method_call method test result:%s\n", retMsg);
    // dbus_free(retMsg);
    /*dbus_message_iter_init_append(msg, &arg);
    if(!dbus_message_iter_append_basic (&arg, DBUS_TYPE_INT32,&a)){
        printf("client Out of Memory1!\n");
        return 0;
    }

    if(!dbus_message_iter_append_basic (&arg, DBUS_TYPE_INT32,&b)){
        printf("client Out of Memory2!\n");
        return 0;
    }

    if(!dbus_connection_send_with_reply (dbconn, msg,&pending, -1)){
        printf("client Out of Memory3!\n");
        return 0;
    }

    if(pending == NULL){
        printf("Pending Call NULL: connection is disconnected \n");
        dbus_message_unref(msg);
        return 0;
    }

    dbus_connection_flush(dbconn);
    dbus_message_unref(msg);
    dbus_pending_call_block (pending);
    msg = dbus_pending_call_steal_reply (pending);

    if (msg == NULL) {
        printf("Reply Null\n");
        return 0;
    }

    dbus_pending_call_unref(pending);

    if (!dbus_message_iter_init(msg, &arg))
        fprintf(stderr, "Message has no arguments!\n");
    else if ( dbus_message_iter_get_arg_type (&arg) != DBUS_TYPE_INT32)
        fprintf(stderr, "Argument is not boolean!\n");
    else
        dbus_message_iter_get_basic (&arg, &result);

    dbus_message_unref(msg); */

    return result;
}

int main(int argc, char **argv)
{
    DBusError dberr;
    DBusConnection *dbconn;
    // DBusMessage *msg;
    // DBusMessageIter args;
    // pthread_t tid;
    // pthread_create(&tid,NULL,mainloop,NULL);

    dbus_error_init(&dberr);
    dbconn = dbus_bus_get(DBUS_BUS_SESSION, &dberr);

    if (dbus_error_is_set(&dberr)) {
        printf("getting session bus failed: %s\n", dberr.message);
        dbus_error_free(&dberr);
        return EXIT_FAILURE;
    }

    if (dbconn == NULL) {
        printf("connect bus failed: %s\n", dberr.message);
        return EXIT_FAILURE;
    }
    const char *param = "org.deepin.demo";
    int result = method_get(dbconn, param);
    printf("method call result: %d\n", result);
    return 0;
}
