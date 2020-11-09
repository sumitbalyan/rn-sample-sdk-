//
//  SSOpening.h
//  JustIN Mobile SDK
//
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

/**
 Defines the opening mode with the lock.

    typedef NS_ENUM(uint8_t, SSOpeningMode) {
        // The lock will only open if you use an authorized key.
        kOpeningStandardMode = 0x00,

        // If both the user and the lock are set to support office mode and the user is authorized to
        // gain access to the lock, that lock will be opened for any user who wishes to gain access.
        kOpeningOfficeMode = 0x01
    };

 @since v2.1
 */
@interface SSOpening : NSObject

typedef NS_ENUM(uint8_t, SSOpeningMode) {
    /**
     The lock will only open if you use an authorized key.
     */
    kOpeningStandardMode = 0x00,
    
    /**
     If both the user and the lock are set to support office mode and the user is authorized to
     gain access to the lock, that lock will be opened for any user who wishes to gain access.
     */
    kOpeningOfficeMode = 0x01
};

@end
