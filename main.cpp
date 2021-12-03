#include "hFramework.h"
#include "stddef.h"
#include "stdio.h"
#include "Lego_Touch.h"

using namespace hSensors;

hLegoSensor_simple ls1(hSens5);
Lego_Touch legoBtn(ls1);

bool current_lego_btn = false;
bool previous_lego_btn = false;
bool current_hBtn1 = false;
bool current_hBtn2 = false;
bool previous_hBtn1 = false;
bool previous_hBtn2 = false;
bool engine_run = false;

uint8_t press_num = 0u;

// void hMain()
// {
//     sys.setLogDev(&Serial);

//     while (1)
//     {
//         current_lego_btn = legoBtn.isPressed();       //read buttons states
//         current_hBtn1 = hBtn1.isPressed();
//         current_hBtn2 = hBtn2.isPressed();

//         if (current_lego_btn && !previous_lego_btn)   //if rising slope is detected on button input
//         {                                             //toggle engine state and increment number of presses
//             engine_run = !engine_run;
//             ++press_num;
//             printf("Lego button pressed %u times\r\n", press_num);
//         }

//         previous_lego_btn = current_lego_btn;   //update previous button state

//         if (engine_run && current_hBtn1)        //turn on engine in one of directions
//         {                                       //if any of hBtns is pressed
//             hMot1.setPower(500);
//         }
//         else if (engine_run && current_hBtn2)
//         {
//             hMot1.setPower(-500);
//         }
//         else
//         {
//             hMot1.setPower(0);  //turn off if no button is pressed
//         }

//         sys.delay(50);          //debouncing
//     }
// }

// void hMain()
// {
//     sys.setLogDev(&Serial);

//     while(1)
//     {
//         current_lego_btn = legoBtn.isPressed();
//         current_hBtn1 = hBtn1.isPressed();
//         current_hBtn2 = hBtn2.isPressed();

//         if (current_lego_btn && !previous_lego_btn)   //if rising slope is detected on button input
//         {   
//                 hMot1.setPower(300);
//             printf("Lego button pressed %u times\r\n", ++press_num);
//         }
//         else if (!current_lego_btn && previous_lego_btn)
//         {     
//             hMot1.setPower(0);  //toggle engine state and increment number of presses
//             // hMot2.rotRel(90, 200);  
//             printf("Lego button released %u times\r\n", press_num);    
//         }    

//         if (current_hBtn1 && !previous_hBtn1)   //if rising slope is detected on hbutton1 input
//         {   
//             if (press_num%2 == 0)
//                 hMot2.setPower(200);
//             else
//                 hMot2.setPower(-200);                     //toggle engine state and increment number of presses
//         }
//         else if (!current_hBtn1 && previous_hBtn1)
//         {     
//             hMot2.setPower(0);  //toggle engine state and increment number of presses
//         } 

//         if (current_hBtn2 && !previous_hBtn2)   //if rising slope is detected on hbutton2 input
//         {   
//             if (press_num%2 == 0)
//                 hMot3.setPower(200);
//             else
//                 hMot3.setPower(-200);                     //toggle engine state and increment number of presses
//         }
//         else if (!current_hBtn2 && previous_hBtn2)
//         {     
//             hMot3.setPower(0);  //toggle engine state and increment number of presses
//         } 

//         previous_lego_btn = current_lego_btn;   //update previous button state
//         previous_hBtn1 = current_hBtn1;
//         previous_hBtn2 = current_hBtn2;
//         // printf("Lego button released %u times\r\n", press_num);   
//         sys.delay(50); 
//     }
// }

void hMain()
{
    sys.setLogDev(&Serial);
    hMot3.setEncoderPolarity(Polarity::Reversed);

    while(1)
    {
        current_lego_btn = legoBtn.isPressed();
        if (current_lego_btn && !previous_lego_btn)   //if rising slope is detected on button input
        {   
            if (press_num%2 == 0)
                hMot3.rotRel(100, 200U);
            else
                hMot3.rotRel(-100, 200U);
            printf("Lego button pressed %u times\r\n", ++press_num);
        }
        // else if (!current_lego_btn && previous_lego_btn)
        // {     
        //     hMot3.setPower(0);  //toggle engine state and increment number of presses
        //     // hMot2.rotRel(90, 200);  
        //     printf("Lego button released %u times\r\n", press_num);    
        // } 
        previous_lego_btn = current_lego_btn;
        sys.delay(50);
    }
}