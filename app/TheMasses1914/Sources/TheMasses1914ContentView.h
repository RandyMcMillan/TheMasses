//
//	TheMasses1914ContentView.h
//	TheMasses1914 v2.8.6
//
//	Created by Julius Oklamcak on 2011-07-01.
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

#import <UIKit/UIKit.h>

#import "TheMasses1914ThumbView.h"

@class TheMasses1914ContentView;
@class TheMasses1914ContentPage;
@class TheMasses1914ContentThumb;

@protocol TheMasses1914ContentViewDelegate <NSObject>

@required // Delegate protocols

- (void)contentView:(TheMasses1914ContentView *)contentView touchesBegan:(NSSet *)touches;

@end

@interface TheMasses1914ContentView : UIScrollView

@property (nonatomic, weak, readwrite) id <TheMasses1914ContentViewDelegate> message;

- (instancetype)initWithFrame:(CGRect)frame fileURL:(NSURL *)fileURL page:(NSUInteger)page password:(NSString *)phrase;

- (void)showPageThumb:(NSURL *)fileURL page:(NSInteger)page password:(NSString *)phrase guid:(NSString *)guid;

- (id)processSingleTap:(UITapGestureRecognizer *)recognizer;

- (void)zoomIncrement:(UITapGestureRecognizer *)recognizer;
- (void)zoomDecrement:(UITapGestureRecognizer *)recognizer;
- (void)zoomResetAnimated:(BOOL)animated;

@end

#pragma mark -

//
//	TheMasses1914ContentThumb class interface
//

@interface TheMasses1914ContentThumb : TheMasses1914ThumbView

@end
