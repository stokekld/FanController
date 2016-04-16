#!/bin/bash
NAME=fanController
PIDFILE=/var/run/$NAME.pid

case $1 in 

	start)
#		/home/pi/Documents/fanController/fanController -d
		PID=`/home/pi/Documents/fanController/fanController -d > /dev/null 2>&1 & echo $!`
    		#echo "Saving PID" $PID " to " $PIDFILE
        	if [ -z $PID ]; then
            		printf "%s\n" "Fail"
        	else
            		echo $PID > $PIDFILE
            		printf "%s\n" "Ok"
        	fi

		echo "hola embebidos"
		;;
		status)
		        printf "%-50s" "Checking $NAME..."
		        if [ -f $PIDFILE ]; then
		            PID=`cat $PIDFILE`
		            if [ -z "`ps axf | grep ${PID} | grep -v grep`" ]; then
                		printf "%s\n" "Process dead but pidfile exists"
		            else
                		echo "Running"
		           fi
		        else
		            printf "%s\n" "Service not running"
		        fi
		;;
	stop)
		if [ -f /var/run/$NAME.pid ]; then 
			kill -15 $PID
		fi
		echo "nos vemos"
		;;
	*)
		echo "Usage: $0 {status|start|stop}"
        exit 1

esac 

