//
//  SSLockOpeningParams.h
//  JustIN Mobile SDK
//
//  Created by Xabier Gorostidi on 26/01/2018.
//  Copyright (c) 2018 Copyright Salto Systems.
//  All rights reserved.
//
//  Use of binaries contained within SALTO JustIN Mobile's SDK is permitted only to enable the
//  integration of the Systems Systems platform by customers of Salto Systems.
//  Decompilation and modification is not allowed.
//  Neither the name of Salto Systems nor JustIN nor the names of its contributors may be used to
//  endorse or promote products derived from this software without specific prior written permission.
//  Redistribution of binaries is disallowed except with specific prior written permission.
//  Any such redistribution must retain the above copyright notice, this list of conditions and the
//  following disclaimer.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
//  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
//  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <Foundation/Foundation.h>
#import "SSOpening.h"

/**
 Represents additional parameters that might be specified for an opening process.

 @since v2.1
 */
@interface SSLockOpeningParams : NSObject

/**
 The opening mode for the lock. Check `SSOpening` for available values.

 @since v2.1
 */
@property (nonatomic, readonly) SSOpeningMode openingMode;

/**
 Returns an `SSLockOpeningParams` object initialized by copying the values from the opening mode.
 
 @param openingMode Define an opening mode. Check `SSOpening` for available values.

 @since v2.1
 */
- (instancetype)initWithOpeningMode:(SSOpeningMode)openingMode;

- (instancetype)init NS_UNAVAILABLE;

@end
