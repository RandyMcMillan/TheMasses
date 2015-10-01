//
//	TheMasses1913MainPagebar.h
//	TheMasses1913 v2.8.6
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

#import <UIKit/UIKit.h>

#import "TheMasses1913ThumbView.h"

@class TheMasses1913MainPagebar;
@class TheMasses1913TrackControl;
@class TheMasses1913PagebarThumb;
@class TheMasses1913Document;

@protocol TheMasses1913MainPagebarDelegate <NSObject>

@required // Delegate protocols

- (void)pagebar:(TheMasses1913MainPagebar *)pagebar gotoPage:(NSInteger)page;

@end

@interface TheMasses1913MainPagebar : UIView

@property (nonatomic, weak, readwrite) id <TheMasses1913MainPagebarDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame document:(TheMasses1913Document *)object;

- (void)updatePagebar;

- (void)hidePagebar;
- (void)showPagebar;

@end

#pragma mark -

//
//	TheMasses1913TrackControl class interface
//

@interface TheMasses1913TrackControl : UIControl

@property (nonatomic, assign, readonly) CGFloat value;

@end

#pragma mark -

//
//	TheMasses1913PagebarThumb class interface
//

@interface TheMasses1913PagebarThumb : TheMasses1913ThumbView

- (instancetype)initWithFrame:(CGRect)frame small:(BOOL)small;

@end

#pragma mark -

//
//	TheMasses1913PagebarShadow class interface
//

@interface TheMasses1913PagebarShadow : UIView

@end
