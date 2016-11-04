//
//  PPTextLayoutLine.h
//  PPAsyncDrawingKit
//
//  Created by DSKcpp on 2016/10/26.
//  Copyright © 2016年 DSKcpp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import "PPTextLayoutFrame.h"

@interface PPTextLayoutLine : NSObject
@property (nonatomic, assign) CTLineRef lineRef;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign, readonly) BOOL truncated;
@property (nonatomic, assign, readonly) PPFontMetrics lineMetrics;
@property (nonatomic, assign, readonly) PPFontMetrics originalLineMetrics;
@property (nonatomic, assign, readonly) NSRange stringRange;
@property (nonatomic, assign, readonly) CGPoint baselineOrigin;
@property (nonatomic, assign, readonly) CGPoint originalBaselineOrigin;
@property (nonatomic, weak) PPTextLayout *layout;

@property (nonatomic, assign, readonly) CGRect fragmentRect;
@property (nonatomic, assign, readonly) CGRect originalFragmentRect;
- (instancetype)initWithCTLine:(CTLineRef)lineRef origin:(CGPoint)origin layout:(PPTextLayout *)layout;
- (instancetype)initWithCTLine:(CTLineRef)lineRef origin:(CGPoint)origin layout:(PPTextLayout *)layout truncatedLine:(CTLineRef)truncatedLine;
- (void)setupWithCTLine;

- (void)enumerateLayoutRunsUsingBlock:(void(^)(NSDictionary *attributes, NSRange range))block;
- (NSUInteger)characterIndexForBoundingPosition:(CGPoint)position;
- (CGPoint)baselineOriginForCharacterAtIndex:(NSUInteger)index;
- (NSInteger)locationDeltaFromRealRangeToLineRefRange;
- (CGFloat)offsetXForCharacterAtIndex:(NSUInteger)index;
@end
