//
//  EpsonUtils.m
//
//  Created by Till POS on 14/09/21.
//

#import <Foundation/Foundation.h>
#import "EpsonUtils.h"
#import "EpsonPrinterSDK.h"

@implementation EpsonUtils

+ (NSString *)makeErrorMessage:(Epos2PrinterStatusInfo *)status
{
    NSMutableString *errMsg = [[NSMutableString alloc] initWithString:@""];

    if (status.getOnline == EPOS2_FALSE) {
        [errMsg appendString:@"Printer is offline.\n"];
    }
    if (status.getConnection == EPOS2_FALSE) {
        [errMsg appendString:@"Please check the connection of the printer and the mobile terminal.\nConnection get lost.\n"];
    }
    if (status.getCoverOpen == EPOS2_TRUE) {
        [errMsg appendString:@"Please close roll paper cover.\n"];
    }
    if (status.getPaper == EPOS2_PAPER_EMPTY) {
        [errMsg appendString:@"Please check roll paper.\n"];
    }
    if (status.getPaperFeed == EPOS2_TRUE || status.getPanelSwitch == EPOS2_SWITCH_ON) {
        [errMsg appendString:@"Please release a paper feed switch.\n"];
    }
    if (status.getErrorStatus == EPOS2_MECHANICAL_ERR || status.getErrorStatus == EPOS2_AUTOCUTTER_ERR) {
        [errMsg appendString:@"Please remove jammed paper and close roll paper cover.\nRemove any jammed paper or foreign substances in the printer, and then turn the printer off and turn the printer on again.\n"];
        [errMsg appendString:@"Then, If the printer doesn\'t recover from error, please cycle the power switch.\n"];
    }
    if (status.getErrorStatus == EPOS2_UNRECOVER_ERR) {
        [errMsg appendString:@"Please cycle the power switch of the printer.\nIf same errors occurred even power cycled, the printer may out of order."];
    }

    if (status.getErrorStatus == EPOS2_AUTORECOVER_ERR) {
        if (status.getAutoRecoverError == EPOS2_HEAD_OVERHEAT) {
            [errMsg appendString:@"Please wait until error LED of the printer turns off. \n"];
            [errMsg appendString:@"Print head of printer is hot.\n"];
        }
        if (status.getAutoRecoverError == EPOS2_MOTOR_OVERHEAT) {
            [errMsg appendString:@"Please wait until error LED of the printer turns off. \n"];
            [errMsg appendString:@"Motor Driver IC of printer is hot.\n"];
        }
        if (status.getAutoRecoverError == EPOS2_BATTERY_OVERHEAT) {
            [errMsg appendString:@"Please wait until error LED of the printer turns off. \n"];
            [errMsg appendString:@"Battery of printer is hot.\n"];
        }
        if (status.getAutoRecoverError == EPOS2_WRONG_PAPER) {
            [errMsg appendString:@"Please set correct roll paper.\n"];
        }
    }
    if (status.getBatteryLevel == EPOS2_BATTERY_LEVEL_0) {
        [errMsg appendString:@"Please connect AC adapter or change the battery.\nBattery of printer is almost empty.\n"];
    }
    if (status.getRemovalWaiting == EPOS2_REMOVAL_WAIT_PAPER) {
        [errMsg appendString:@"Please remove paper.\n"];
    }
    if (status.getUnrecoverError == EPOS2_HIGH_VOLTAGE_ERR ||
        status.getUnrecoverError == EPOS2_LOW_VOLTAGE_ERR) {
        [errMsg appendString:@"Please check the voltage status.\n"];
    }
    

    return errMsg;
}

@end
