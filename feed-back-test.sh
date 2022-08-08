#!/bin/sh

dbus-send --system --dest=org.keti.DBus.Feedback --type=method_call --print-reply /org/keti/DBus/Feedback org.keti.DBus.Feedback.Level1 string:"level 1"
dbus-send --system --dest=org.keti.DBus.Feedback --type=method_call --print-reply /org/keti/DBus/Feedback org.keti.DBus.Feedback.Level2 string:"level 2"
dbus-send --system --dest=org.keti.DBus.Feedback --type=method_call --print-reply /org/keti/DBus/Feedback org.keti.DBus.Feedback.Level3 string:"level 3"
dbus-send --system --dest=org.keti.DBus.Feedback --type=method_call --print-reply /org/keti/DBus/Feedback org.keti.DBus.Feedback.Level4 string:"level 4"