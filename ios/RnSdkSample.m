#import "RnSdkSample.h"

@import SaltoJustINMobileSDK

@implementation RnSdkSample

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(sampleMethod:(NSString *)key callback:(RCTResponseSenderBlock)callback)
{
    // TODO: Implement some actually useful functionality
    //callback(@[[NSString stringWithFormat: @"numberArgument: %@ stringArgument: %@", numberArgument, stringArgument]]);

    NSError * keyGenerationError;
    SSMobileKey *key = [[SSMobileKey alloc] initWithHexData:@"C0020100C120C3BD00E770C1F62B89F1223D8D2E5EBAAE16BB54A246254B7193EBD485533C45C210EC4D4A0C8FF1D6F529A9864145DC1ADE"
                                                      error:&keyGenerationError];
    if (keyGenerationError != nil) {
        [self finishExecution];
        NSLog(@"%@", [keyGenerationError description]);
        return;
    }
    
    // Invoke the method to start the opening process
    [SSJustinBleInstance startOpeningWithMobileKey:key peripheralFound:^{
        // A SALTO lock is found and it will connect to it and start the secure process
        self->spiOpenning.color = [UIColor colorWithRed:0/255.0f green:129/255.0f blue:201/255.0f alpha:1.0f];
    } success:^(SSResult * result) {
        // Authentication process finished with result code
        [self finishExecution];
        NSString *resultMessage;
        if ([result getOpResult] == AUTH_SUCCESS_UNKNOWN_RESULT) {
            resultMessage = nil;
        } else if ([result getOpResult] == AUTH_SUCCESS_ACCESS_GRANTED) {
            resultMessage = @"\nAccess granted";
        } else if ([result getOpResult] == AUTH_SUCCESS_ACCESS_REJECTED) {
            resultMessage = @"\nAccess rejected";
        }
        
        if (resultMessage) {
            UIAlertController * alert = [UIAlertController alertControllerWithTitle:@"Result"
                                                                            message:resultMessage
                                                                     preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction * action = [UIAlertAction
                                      actionWithTitle:@"OK"
                                      style:UIAlertActionStyleDefault
                                      handler:nil];
            [alert addAction:action];
            [self presentViewController:alert
                               animated:YES
                             completion:nil];
                             callback(@[[NSNull null], resultMessage]);
        }
        else {
            callback(@[[NSNull null], "No Result Error!!"]);
        }
    } failure:^(NSError *error) {
        // An error has occurred
        [self finishExecution];
        UIAlertController * alert = [UIAlertController alertControllerWithTitle:@"Error"
                                                                        message:error.localizedDescription
                                                                 preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction * action = [UIAlertAction
                                  actionWithTitle:@"OK"
                                  style:UIAlertActionStyleDefault
                                  handler:nil];
        [alert addAction:action];
        [self presentViewController:alert
                           animated:YES
                         completion:nil];
                        callback(@[[NSNull null], error.localizedDescription]);
    }];
}


@end
