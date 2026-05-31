'use strict';

goog.provide('Blockly.Blocks.LA4WDCar');

goog.require('Blockly.Blocks');

//////////////////颜色/////////////////////
Blockly.Blocks.LA4WDCar.HUE = 100;


//////////////////////////////ksLA4WDCar/////////////////////////////
Blockly.Blocks.ks4wd_FRONT = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_msg_front)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    .appendField(Blockly.ks4wd_msg_speed);
    this.appendValueInput("speed_F", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};

////////////////////////////back////////////////
Blockly.Blocks.ks4wd_BACK = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_msg_back)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    .appendField(Blockly.ks4wd_msg_speed);
    this.appendValueInput("speed_B", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};

////////////////////////////left////////////////
Blockly.Blocks.ks4wd_ROTATE_LEFT = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_msg_rotate_left)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    .appendField(Blockly.ks4wd_msg_speed);
    this.appendValueInput("speed_L", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};


////////////////////////////right////////////////
Blockly.Blocks.ks4wd_ROTATE_RIGHT = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_msg_rotate_right)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    .appendField(Blockly.ks4wd_msg_speed);
    this.appendValueInput("speed_R", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};



////////////////////////////stop////////////////
Blockly.Blocks.ks4wd_STOP = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_msg_stop)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};



///////////////////////////左右轮差速前进////////////////
Blockly.Blocks.ks4wd_FORWARD_TURN = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    //.appendField(Blockly.ks4wd_front)
    .appendField(Blockly.ks4wd_msg_forward_turn)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    .appendField(Blockly.ks4wd_Left_wheel);
    this.appendValueInput("speed_F", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM")
    .appendField(Blockly.ks4wd_Right_wheel);
    this.appendValueInput("speed_F2", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};

////////////////////////////左右轮差速后退////////////////
Blockly.Blocks.ks4wd_BACKWARD_TURN = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    
    this.appendDummyInput("")
    //.appendField(Blockly.ks4wd_back)
    .appendField(Blockly.ks4wd_msg_backward_turn)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/runing.png", 78, 52))
    //.appendField(Blockly.ks4wd_speed);
    .appendField(Blockly.ks4wd_Left_wheel);
    this.appendValueInput("speed_B", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM")
    .appendField(Blockly.ks4wd_Right_wheel);
    this.appendValueInput("speed_B2", Number)
    .setCheck(Number);
    this.appendDummyInput("")
    .appendField("PWM");
 
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};





///////////////超声波/////////////////////////
Blockly.Blocks.ks4wd_sr04 = {
  init: function () {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
    .appendField(Blockly.ks4wd_sr01)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/sr01.png", 50, 40));
    
    this.setInputsInline(true);
    this.setOutput(true, Number);
    this.setTooltip(Blockly.MIXLY_TOOLTIP_BLOCKGROUP_CHAOSHENGBO);
  }
};











///////////循迹传感器////////////////////
Blockly.Blocks.ks4wd_track = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
        .appendField(new Blockly.FieldDropdown([[Blockly.ks4wd_L_track, "track_left"],[Blockly.ks4wd_C_track, "track_center"],[Blockly.ks4wd_R_track, "track_right"]]), 'track');
    this.appendDummyInput("")
    //.appendField("track")
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/track.png", 90, 90));
    this.setOutput(true, Number);
    this.setInputsInline(true);
    this.setTooltip('');
  }
};





////////////////红外接收////////////////////////////
//红外接收模块
Blockly.Blocks.ks4wd_ir_r = {
    init: function () {
        this.setColour(Blockly.Blocks.LA4WDCar.HUE);
        this.appendDummyInput("")
            .appendField(new Blockly.FieldTextInput('ir_rec'), 'VAR')
            .appendField(Blockly.ks4wd_ir_R)
            .appendField(new Blockly.FieldImage("../../media/LA4WDCar/irr_svg.svg", 150, 85));
        this.appendStatementInput('DO')
            .appendField(Blockly.ks4wd_ir_RD);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setInputsInline(true);
        this.setTooltip(Blockly.MIXLY_IR_RECIEVE_TOOLTIP);
    },
    getVars: function () {
        return [this.getFieldValue('VAR')];
    },
    renameVar: function (oldName, newName) {
        if (Blockly.Names.equals(oldName, this.getFieldValue('VAR'))) {
            this.setTitleValue(newName, 'VAR');
        }
    }
};

//////////////////////蓝牙////////////////////////////
Blockly.Blocks.ks4wd_bluetooth = {
    init: function () {
        this.setColour(Blockly.Blocks.LA4WDCar.HUE);
        this.appendDummyInput("")
            .appendField(new Blockly.FieldTextInput('bluetooth_val'), 'VAL')
            .appendField(Blockly.ks4wd_Bluetooth)
            .appendField(new Blockly.FieldImage("../../media/LA4WDCar/bluetooth4.0.svg", 90, 90))
        this.appendStatementInput('DO')
            .appendField(Blockly.ks4wd_Bluetooth_rec);
        this.setPreviousStatement(true);
        this.setNextStatement(true);
        this.setInputsInline(true);
        this.setTooltip("bluetooth");
    },
    getVars: function () {
        return [this.getFieldValue('VAL')];
    },
    renameVar: function (oldName, newName) {
        if (Blockly.Names.equals(oldName, this.getFieldValue('VAL'))) {
            this.setTitleValue(newName, 'VAL');
        }
    }
};


var KW_IRKEY = [["1", "IR_KEYCODE_1"], ["2", "IR_KEYCODE_2"], ["3", "IR_KEYCODE_3"], ["4", "IR_KEYCODE_4"], ["5", "IR_KEYCODE_5"], ["6", "IR_KEYCODE_6"], ["7", "IR_KEYCODE_7"], ["8", "IR_KEYCODE_8"], ["9", "IR_KEYCODE_9"], ["0", "IR_KEYCODE_0"], ["*", "IR_KEYCODE_STAR"], ["#", "IR_KEYCODE_POUND"], ["UP", "IR_KEYCODE_UP"], ["DOWN", "IR_KEYCODE_DOWN"], ["OK", "IR_KEYCODE_OK"], ["LEFT", "IR_KEYCODE_LEFT"], ["RIGHT", "IR_KEYCODE_RIGHT"]];

//初始化红外遥控 引脚value
Blockly.Blocks.ks_initir = {
  init: function () {
    this.setColour(100);
    this.appendDummyInput("")
      .appendField(Blockly.ks_INITIR)
	  .appendField(new Blockly.FieldImage("../../media/LA4WDCar/irr_svg.svg", 100, 50));
    this.appendValueInput("initir", Number)
      .setCheck(Number);
    this.setInputsInline(true);
    this.setPreviousStatement(true, null);
    this.setInputsInline(true);
    this.setNextStatement(true, null);
  }
};
// 普通红外遥控按键（下拉，返回boolean）
Blockly.Blocks.ks_irKeyPress = {
  init: function () {
    this.setColour(100);
    this.appendDummyInput("")
      .appendField(Blockly.ks_IRKEYPRESS)
	  .appendField(new Blockly.FieldImage("../../media/LA4WDCar/irr_svg.svg", 90, 45))
      .appendField(new Blockly.FieldDropdown(KW_IRKEY), "Irkey");
    this.setOutput(true, Boolean);
    this.setTooltip('');
  }
};


///////////Infrared obstacle avoidance sensor///////////////
Blockly.Blocks.ks_Tank_IR_Avoidance = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
    .appendField(new Blockly.FieldDropdown([[Blockly.ks4wd_LEFT_IR_Avoid, "left_IR"], [Blockly.ks4wd_RIGHT_IR_Avoid, "right_IR"]]), "IR_avoid")
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/iravoid.png", 80, 40));
    
    this.setInputsInline(true);
    this.setOutput(true, Number);
    this.setTooltip('');
  }
};

///////////光线传感器///////////////
Blockly.Blocks.ks_Tank_light = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
    .appendField(new Blockly.FieldDropdown([[Blockly.ks4wd_LEFT_Light, "left_light"], [Blockly.ks4wd_RIGHT_Light, "right_light"]]), "light")
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/light.svg", 70, 70));
    
    this.setInputsInline(true);
    this.setOutput(true, Number);
    this.setTooltip('');
  }
};




Blockly.Blocks.ks_Tank_SG90servo = {
  init: function() {
    this.setColour(Blockly.Blocks.LA4WDCar.HUE);
    this.appendDummyInput("")
    .appendField(Blockly.ks_MIXLY_Tank_SERVO)
    .appendField(new Blockly.FieldImage("../../media/LA4WDCar/servosg90.png", 70, 60));
    this.appendValueInput("angle", Number)
    .setCheck(Number)
    .setAlign(Blockly.ALIGN_RIGHT)
    .appendField("0~180");
    
    this.setPreviousStatement(true);
    this.setNextStatement(true);
    this.setInputsInline(true);
  }
};



//////////////////////////////DEsktop_Car/////////////////////////////
