//
//	TheMasses1912ThumbQueue.m
//	TheMasses1912 v2.8.6
//
//	Created by Julius Oklamcak on 2011-09-01.
//	Copyright © 2011-2015 Julius Oklamcak. All rights reserved.
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights to
//	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//	of the Software, and to permit persons to whom the Software is furnished to
//	do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in all
//	copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import "TheMasses1912ThumbQueue.h"

@implementation TheMasses1912ThumbQueue
{
	NSOperationQueue *loadQueue;

	NSOperationQueue *workQueue;
}

#pragma mark - TheMasses1912ThumbQueue class methods

+ (TheMasses1912ThumbQueue *)sharedInstance
{
	static dispatch_once_t predicate = 0;

	static TheMasses1912ThumbQueue *object = nil; // Object

	dispatch_once(&predicate, ^{ object = [self new]; });

	return object; // TheMasses1912ThumbQueue singleton
}

#pragma mark - TheMasses1912ThumbQueue instance methods

- (instancetype)init
{
	if ((self = [super init])) // Initialize
	{
		loadQueue = [NSOperationQueue new];

		[loadQueue setName:@"TheMasses1912ThumbLoadQueue"];

		[loadQueue setMaxConcurrentOperationCount:1];

		workQueue = [NSOperationQueue new];

		[workQueue setName:@"TheMasses1912ThumbWorkQueue"];

		[workQueue setMaxConcurrentOperationCount:1];
	}

	return self;
}

- (void)addLoadOperation:(NSOperation *)operation
{
	if ([operation isKindOfClass:[TheMasses1912ThumbOperation class]])
	{
		[loadQueue addOperation:operation]; // Add to load queue
	}
}

- (void)addWorkOperation:(NSOperation *)operation
{
	if ([operation isKindOfClass:[TheMasses1912ThumbOperation class]])
	{
		[workQueue addOperation:operation]; // Add to work queue
	}
}

- (void)cancelOperationsWithGUID:(NSString *)guid
{
	[loadQueue setSuspended:YES]; [workQueue setSuspended:YES];

	for (TheMasses1912ThumbOperation *operation in loadQueue.operations)
	{
		if ([operation isKindOfClass:[TheMasses1912ThumbOperation class]])
		{
			if ([operation.guid isEqualToString:guid]) [operation cancel];
		}
	}

	for (TheMasses1912ThumbOperation *operation in workQueue.operations)
	{
		if ([operation isKindOfClass:[TheMasses1912ThumbOperation class]])
		{
			if ([operation.guid isEqualToString:guid]) [operation cancel];
		}
	}

	[workQueue setSuspended:NO]; [loadQueue setSuspended:NO];
}

- (void)cancelAllOperations
{
	[loadQueue cancelAllOperations]; [workQueue cancelAllOperations];
}

@end

#pragma mark -

//
//	TheMasses1912ThumbOperation class implementation
//

@implementation TheMasses1912ThumbOperation
{
	NSString *_guid;
}

@synthesize guid = _guid;

#pragma mark - TheMasses1912ThumbOperation instance methods

- (instancetype)initWithGUID:(NSString *)guid
{
	if ((self = [super init]))
	{
		_guid = guid;
	}

	return self;
}

@end
