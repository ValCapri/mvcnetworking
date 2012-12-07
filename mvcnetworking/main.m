//
//  main.m
//  mvcnetworking
//
//  Created by Lionel Schinckus on 2/12/12.
//  Copyright (c) 2012 Lionel Schinckus. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AppDelegate.h"

int main(int argc, char *argv[])
{
	@autoreleasepool {
	    return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
	}
}

void TLog(const char *file, int line, NSString *format, ...) {
	va_list args = NULL;
	NSString *logString = nil;
	
	va_start(args, format);
	logString = [[NSString alloc] initWithFormat:format arguments:args];
	
	va_end(args);
	
	NSDateFormatter *dateFormatter = [NSDateFormatter new];
	[dateFormatter setDateFormat:@"HH:mm:ss.SSS"];
	
	logString = [NSString stringWithFormat:@"%@ %s:%d %@",[dateFormatter stringFromDate:[NSDate date]], file, line, logString];
	
	puts([logString UTF8String]);
}
