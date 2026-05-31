'use strict';

goog.provide('Blockly.Blocks.4WD_Car');

goog.require('Blockly.Arduino');





////////////////////////////////front/////////////////////////*/
Blockly.Arduino.ks4wd_FRONT = function() {
  
  var value_front = Blockly.Arduino.valueToCode(this, 'speed_F', Blockly.Arduino.ORDER_ATOMIC);

  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';

   var code = 'digitalWrite(2,HIGH);\nanalogWrite(5,'+value_front+');\ndigitalWrite(4,LOW);\nanalogWrite(6,'+value_front+');\n'; 
  return code;
};

////////////////////////////////back//////////////////////////
Blockly.Arduino.ks4wd_BACK = function() {
  
  var value_back = Blockly.Arduino.valueToCode(this, 'speed_B', Blockly.Arduino.ORDER_ATOMIC);

  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';
   var code = 'digitalWrite(2,LOW);\nanalogWrite(5,'+value_back+');\ndigitalWrite(4,HIGH);\nanalogWrite(6,'+value_back+');\n'; 
  return code;
};

////////////////////////////////left//////////////////////////
Blockly.Arduino.ks4wd_ROTATE_LEFT = function() {
  
  var value_left = Blockly.Arduino.valueToCode(this, 'speed_L', Blockly.Arduino.ORDER_ATOMIC);

  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';
   var code = 'digitalWrite(2,LOW);\nanalogWrite(5,'+value_left+');\ndigitalWrite(4,LOW);\nanalogWrite(6,'+value_left+');\n'; 
  return code;
};




////////////////////////////////right//////////////////////////
Blockly.Arduino.ks4wd_ROTATE_RIGHT = function() {
  
  var value_right = Blockly.Arduino.valueToCode(this, 'speed_R', Blockly.Arduino.ORDER_ATOMIC);

  //Blockly.Arduino.setups_['setup_back_'] = 'pinMode(4, OUTPUT);\n  pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';
   var code = 'digitalWrite(2,HIGH);\nanalogWrite(5,'+value_right+');\ndigitalWrite(4,HIGH);\nanalogWrite(6,'+value_right+');\n'; 
  return code;
};


////////////////////////////////stop//////////////////////////
Blockly.Arduino.ks4wd_STOP = function() {
  //Blockly.Arduino.setups_['setup_back_'] = 'pinMode(4, OUTPUT);\n  pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';
   var code = 'digitalWrite(2,LOW);\nanalogWrite(5,0);\ndigitalWrite(4,HIGH);\nanalogWrite(6,0);\n'; 
  return code;
};



////////////////////////////////左右轮差速前进//////////////////////////
Blockly.Arduino.ks4wd_FORWARD_TURN = function() {
  
  var value_front = Blockly.Arduino.valueToCode(this, 'speed_F', Blockly.Arduino.ORDER_ATOMIC);
  var value_front2 = Blockly.Arduino.valueToCode(this, 'speed_F2', Blockly.Arduino.ORDER_ATOMIC);

  ////Blockly.Arduino.setups_['setup_back_'] = 'pinMode(4, OUTPUT);\n  pinMode(2, OUTPUT);';//这样会在setup里会重复叠加
  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';

  var code = 'digitalWrite(2,HIGH);\nanalogWrite(5,'+value_front+');\ndigitalWrite(4,LOW);\nanalogWrite(6,'+value_front2+');\n'; 
  return code;
};

////////////////////////////////左右轮差速后退//////////////////////////
Blockly.Arduino.ks4wd_BACKWARD_TURN = function() {
  
  var value_back = Blockly.Arduino.valueToCode(this, 'speed_B', Blockly.Arduino.ORDER_ATOMIC);
  var value_back2 = Blockly.Arduino.valueToCode(this, 'speed_B2', Blockly.Arduino.ORDER_ATOMIC);

  ////Blockly.Arduino.setups_['setup_back_'] = 'pinMode(4, OUTPUT);\n  pinMode(2, OUTPUT);';  //这样会在setup里会重复叠加
  Blockly.Arduino.setups_['setup_output_m1'] = 'pinMode(2, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p1'] = 'pinMode(5, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_m2'] = 'pinMode(4, OUTPUT);';
  Blockly.Arduino.setups_['setup_output_p2'] = 'pinMode(6, OUTPUT);';
   var code = 'digitalWrite(2,LOW);\nanalogWrite(5,'+value_back+');\ndigitalWrite(4,HIGH);\nanalogWrite(6,'+value_back2+');\n'; 
  return code;
};











///////////////////////Tank超声波//////////////////////
Blockly.Arduino.ks4wd_sr04 = function () {
    Blockly.Arduino.setups_['setup_output_T'] = 'pinMode(12, OUTPUT);';
    Blockly.Arduino.setups_['setup_output_E'] = 'pinMode(13, INPUT);';
    var funcName = 'checkdistance';
    var code = 'float' + ' ' + funcName + '() {\n'
  + '  digitalWrite(12, LOW);\n' + '  delayMicroseconds(2);\n'
  + '  digitalWrite(12, HIGH);\n' + '  delayMicroseconds(10);\n'
  + '  digitalWrite(12, LOW);\n'
  + '  float distance = pulseIn(13, HIGH) / 58.00;\n'
  + '  delay(10);\n' + '  return distance;\n'
  + '}\n';
    Blockly.Arduino.definitions_[funcName] = code;
    return [funcName + '()', Blockly.Arduino.ORDER_ATOMIC];
};


//////////////////////////循迹模块///////////////////////////
Blockly.Arduino.ks4wd_track = function() {
  var dropdown_type = this.getFieldValue('track');
  Blockly.Arduino.setups_['setup_output_trackleft'] = 'pinMode(7, INPUT);';
  Blockly.Arduino.setups_['setup_output_trackcenter'] = 'pinMode(8, INPUT);';
  Blockly.Arduino.setups_['setup_output_trackright'] = 'pinMode(9, INPUT);';

  var code = '';
  if (dropdown_type == "track_left") code += 'digitalRead(7)';
  if (dropdown_type == "track_center") code += 'digitalRead(8)';
  if (dropdown_type == "track_right") code += 'digitalRead(9)';
  return [code, Blockly.Arduino.ORDER_ATOMIC];
};




///////////////////////////////舵机2/////////////////////////
  Blockly.Arduino.ks4wd_servo2 = function() {

  var value_degree = Blockly.Arduino.valueToCode(this, 'angle', Blockly.Arduino.ORDER_ATOMIC);

  Blockly.Arduino.definitions_['1var123'] = 'const int servopin = A3;\nint myangle;\nint pulsewidth;\n';
  Blockly.Arduino.definitions_['2var_angle'] = 'void servopulse(int servopin,int myangle)\n{\n  for(int i=0; i<5; i++)\n{\n pulsewidth = (myangle*11+500);\n  digitalWrite(servopin,HIGH);\n  delayMicroseconds(pulsewidth);\n  digitalWrite(servopin,LOW);\n  delay(20-pulsewidth/1000);\n}\n}\n';

  Blockly.Arduino.setups_['setup_servo'] = 'pulsewidth = 0;\n  pinMode(A3, OUTPUT);';
  
  var code = ' servopulse(servopin,'+value_degree+');\n';
  return code;
};

////////////////////////////////ks4wd_Matrix//////////////////////////
///////////////////////16*8点阵/////////////////////////////
//初始化
  Blockly.Arduino.Matrix_16and8_Init_4wd = function() {
   var SDA = this.getFieldValue('SDA');
   var SCL = this.getFieldValue('SCL');
   Blockly.Arduino.definitions_['1iic_scl'] = '#define IIC_SCL  '+SCL+'\n';
    Blockly.Arduino.definitions_['1iic_sda'] = '#define IIC_SDA  '+SDA+'\n';
    Blockly.Arduino.definitions_['1line'] = 'unsigned char data_line = 0;\n';
    Blockly.Arduino.definitions_['1count01'] = 'unsigned char delay_count = 0;\n';
    Blockly.Arduino.definitions_['3iic_start'] = 'void IIC_start()\n{\n  digitalWrite(IIC_SCL,LOW);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SDA,HIGH);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SCL,HIGH);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SDA,LOW);\n  delayMicroseconds(3);}\n';
    Blockly.Arduino.definitions_['4iic_send'] =  'void IIC_send(unsigned char send_data)\n{\n  for(char i = 0;i < 8;i++)\n  {\n      digitalWrite(IIC_SCL,LOW);\n      delayMicroseconds(3); \n      if(send_data & 0x01)\n      {\n        digitalWrite(IIC_SDA,HIGH);\n      }\n      else\n      {\n        digitalWrite(IIC_SDA,LOW);\n      }\n      delayMicroseconds(3);\n      digitalWrite(IIC_SCL,HIGH); \n      delayMicroseconds(3);\n      send_data = send_data >> 1;\n  }\n}\n';
    Blockly.Arduino.definitions_['5iic_end'] = 'void IIC_end()\n{\n  digitalWrite(IIC_SCL,LOW);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SDA,LOW);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SCL,HIGH);\n  delayMicroseconds(3);\n  digitalWrite(IIC_SDA,HIGH);\n  delayMicroseconds(3);}\n';
    Blockly.Arduino.setups_['setup_iic'] = '  pinMode(IIC_SCL,OUTPUT);\n  pinMode(IIC_SDA,OUTPUT);\n  digitalWrite(IIC_SCL,LOW);\n  digitalWrite(IIC_SDA,LOW);\n  IIC_start();\n    IIC_send(0x40);\n    IIC_end();\n    IIC_start();\n    IIC_send(0xc0);';

   var code='';
   return code;
 };
//点阵屏显示_显示图案
Blockly.Arduino.display_Matrix16and8_DisplayChar_4wd = function() {
  var matrixType = this.getFieldValue('TYPE');
  var matrixName = this.getFieldValue('matrixName');
  var NO = Blockly.Arduino.valueToCode(this, 'NO', Blockly.Arduino.ORDER_ATOMIC);
  var dotMatrixArray = Blockly.Arduino.valueToCode(this, 'LEDArray', Blockly.Arduino.ORDER_ASSIGNMENT);

  var code = 'IIC_start();\n    IIC_send(0xc0);\n    for(char i = 0;i < 16;i++)\n    {\n       IIC_send('+dotMatrixArray+'[i]);\n    }\n    if(++delay_count >= 10)\n    {\n      delay_count = 0;\n      data_line++;\n      if(data_line >= 4)\n      {\n        data_line = 0;\n      }\n    }\n    IIC_end();\n    IIC_start();\n    IIC_send(0x8A);\n    IIC_end();\n';
  
  return code;
};

//点阵数组
Blockly.Arduino.display_Matrix16and8_LedArray_4wd = function() {
  var varName = this.getFieldValue('VAR');
  var a = new Array();
  for (var i = 1; i < 17; i++) {  //有16列
    a[i] = new Array();
    for (var j = 1; j < 9; j++) {  //8行
      a[i][9-j] = (this.getFieldValue('a' + i + j) == "TRUE") ? 1 : 0;
    }
  }
  var code = '{';
  for (var i = 1; i < 17; i++) {
    var tmp = ""
    for (var j = 1; j < 9; j++) {
      tmp += a[i][j];
    }
    tmp = (parseInt(tmp, 2)).toString(16)
    if (tmp.length == 1) tmp = "0" + tmp;
    code += '0x' + tmp + ((i != 16) ? ',' : '');
  }
  code += '};';
  //Blockly.Arduino.definitions_[varName] = "uint8_t " + varName + "[8]=" + code;
  Blockly.Arduino.definitions_[varName] = "const uint8_t " + varName + "[16]=" + code;
  return [varName, Blockly.Arduino.ORDER_ATOMIC];
};

///////////////显示表情//////////////////////
Blockly.Arduino.ks4wd_matrix = function() {

  Blockly.Arduino.definitions_['1start01'] = 'unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};\n';
  Blockly.Arduino.definitions_['2front'] = 'unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};\n';
  Blockly.Arduino.definitions_['3back'] = 'unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};\n';
  Blockly.Arduino.definitions_['4left'] = 'unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};\n';
  Blockly.Arduino.definitions_['5right'] = 'unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};\n';
  Blockly.Arduino.definitions_['6Stop01'] = 'unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};\n';
  Blockly.Arduino.definitions_['7clear'] = 'unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};\n';
  Blockly.Arduino.definitions_['8triange_full'] = 'unsigned char triangle_full[] = {0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80};\n';
  Blockly.Arduino.definitions_['9heart'] = 'unsigned char heart_full[] = {0x00,0x00,0x0C,0x1E,0x3F,0x7F,0xFE,0xFC,0xFE,0x7F,0x3F,0x1E,0x0C,0x00,0x00,0x00};\n';
  Blockly.Arduino.definitions_['atriange_back'] = 'unsigned char triangle_back[] = {0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01};\n';
  Blockly.Arduino.definitions_['bsmile'] = 'unsigned char smile[] = {0x00,0x00,0x00,0x0C,0x02,0x02,0x0C,0x20,0x20,0x20,0x0C,0x02,0x02,0x0C,0x00,0x00};\n';
  Blockly.Arduino.definitions_['csad'] = 'unsigned char sad[] = {0x00,0x00,0x02,0x02,0x02,0x12,0x08,0x04,0x08,0x12,0x22,0x02,0x02,0x00,0x00,0x00};\n';

  var dropdown_type = this.getFieldValue('matrix');
  var code = 'IIC_start();\n    IIC_send(0xc0);\n    for(char i = 0;i < 16;i++)\n    {\n       IIC_send('+dropdown_type+'[i]);\n    }\n    if(++delay_count >= 10)\n    {\n      delay_count = 0;\n      data_line++;\n      if(data_line >= 4)\n      {\n        data_line = 0;\n      }\n    }\n    IIC_end();\n    IIC_start();\n    IIC_send(0x8A);\n    IIC_end();\n';
  
  return code;
};

Blockly.Arduino.ks4wd_light = function() {

  Blockly.Arduino.setups_['setup_input_A1'] = 'pinMode(A1, INPUT);';
  Blockly.Arduino.setups_['setup_input_A2'] = 'pinMode(A2, INPUT);';
  var dropdown_type = this.getFieldValue('light');


  var code = '';
  if (dropdown_type == "left_light") code += 'analogRead(A1)';
  if (dropdown_type == "right_light") code += 'analogRead(A2)';
  return [code, Blockly.Arduino.ORDER_ATOMIC];
};



///////////////////////红外接收///////////////////
Blockly.Arduino.ks4wd_ir_r = function () {
    var variable = Blockly.Arduino.variableDB_.getName(this.getFieldValue('VAR'), Blockly.Variables.NAME_TYPE);
    Blockly.Arduino.definitions_['var_declare' + variable] = 'long ' + variable + ';';
    //var dropdown_pin = Blockly.Arduino.valueToCode(this, 'PIN', Blockly.Arduino.ORDER_ATOMIC);
    var branch = Blockly.Arduino.statementToCode(this, 'DO');
    var branch2 = Blockly.Arduino.statementToCode(this, 'DO2');
    var varName = Blockly.Arduino.variableDB_.getName(this.getFieldValue('VAR'),
       Blockly.Variables.NAME_TYPE);
    Blockly.Arduino.definitions_['1include_IRremote'] = '#include <IRremote.h>\n';
    //Blockly.Arduino.definitions_['var_declare'+varName] = 'long '+varName+';\n';
    Blockly.Arduino.definitions_['2var_ir_recv_A0'] = 'IRrecv irrecv(A0);\ndecode_results results;\n';
    Blockly.Arduino.setups_['setup_ir_recv_A0'] = 'irrecv.enableIRIn();';
    var code = "if (irrecv.decode(&results)) {\n"
    code += '  ' + variable + '=results.value;\n';
    code += '  String type="UNKNOWN";\n';
    ////////////////////////////////////////////////////////////////
    code += '  String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};\n';
    code += '  if(results.decode_type>=1&&results.decode_type<=13){\n';
    code += '    type=typelist[results.decode_type];\n'
    code += '  }\n';
    code += '  Serial.print("IR TYPE:"+type+"  ");\n';
    code += branch;
    code += '  irrecv.resume();\n'
    code += '} else {\n';
    code += branch2;
    code += '}\n';
    return code;
};

/////////////////////////////////////蓝牙////////////////////////////////////
Blockly.Arduino.ks4wd_bluetooth = function () {
  var variable = Blockly.Arduino.variableDB_.getName(this.getFieldValue('VAL'), Blockly.Variables.NAME_TYPE);
  var val = this.getFieldValue('VAL');
  var branch = Blockly.Arduino.statementToCode(this, 'DO');
  //var dropdown_pin1 = Blockly.Arduino.valueToCode(this, 'PIN1', Blockly.Arduino.ORDER_ATOMIC);
  //var dropdown_pin2 = Blockly.Arduino.valueToCode(this, 'PIN2', Blockly.Arduino.ORDER_ATOMIC);


  //Blockly.Arduino.definitions_['include_Soft'] = '#include <SoftwareSerial.h>\n';
  //Blockly.Arduino.definitions_['mySerial'] = 'SoftwareSerial mySerial(0, 1);\n';
  Blockly.Arduino.definitions_['1char'] = 'char '+val+';\n';

  Blockly.Arduino.setups_['2mySerial23'] = 'Serial.begin(9600);';

   var code = 'if (Serial.available())\n{\n  '+val+' = Serial.read();\n';
   code += branch;
   code += '}\n';
  return code;
};


//IR Control
Blockly.Arduino.ks_initir = function () {
	 var value_initir = Blockly.Arduino.valueToCode(this, 'initir', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_initir'] = '#include "IR_remote.h"\n#include "keymap.h"\n'+'IRremote ir('+value_initir+');\n';
	Blockly.Arduino.definitions_['define_initir'] = '#include "IR_remote.h"\n#include "keymap.h"\n';
	Blockly.Arduino.definitions_['define_initir1'] = 'IRremote ir('+value_initir+');\n';
	Blockly.Arduino.setups_['setup_initir1'] = 'IRremote ir('+value_initir+');\n';
	//Blockly.Arduino.setups_['setup_initir'] = 'ir.begin();\n';
	var code = '';
    return code;
};

Blockly.Arduino.ks_irKeyPress = function(){
 var dropdown_Irkey = this.getFieldValue('Irkey');
 var code = 'ir.getIrKey(ir.getCode(),1) == '+dropdown_Irkey+'';
 return [code, Blockly.Arduino.ORDER_ATOMIC]; 
};

//红外避障
Blockly.Arduino.ks_Tank_IR_Avoidance = function() {

  Blockly.Arduino.setups_['setup_input_A1'] = 'pinMode(A1, INPUT);';
  Blockly.Arduino.setups_['setup_input_A2'] = 'pinMode(A2, INPUT);';
  var dropdown_type = this.getFieldValue('IR_avoid');


  var code = '';
  if (dropdown_type == "left_IR") code += 'digitalRead(A1)';
  if (dropdown_type == "right_IR") code += 'digitalRead(A2)';
  return [code, Blockly.Arduino.ORDER_ATOMIC];
};


//光敏值，寻光机器人
Blockly.Arduino.ks_Tank_light = function() {

  Blockly.Arduino.setups_['setup_input_A0'] = 'pinMode(A0, INPUT);';
  Blockly.Arduino.setups_['setup_input_A3'] = 'pinMode(A3, INPUT);';
  var dropdown_type = this.getFieldValue('light');


  var code = '';
  if (dropdown_type == "left_light") code += 'analogRead(A0)';
  if (dropdown_type == "right_light") code += 'analogRead(A3)';
  return [code, Blockly.Arduino.ORDER_ATOMIC];
};




//库文件控制舵机
  Blockly.Arduino.ks_Tank_SG90servo = function() {

  var value_degree = Blockly.Arduino.valueToCode(this, 'angle', Blockly.Arduino.ORDER_ATOMIC);

  Blockly.Arduino.definitions_['include_Servo'] = '#include <Servo.h>\n';
  Blockly.Arduino.definitions_['var_myservo'] = 'Servo myservo;';

  Blockly.Arduino.setups_['setup_servo'] = 'myservo.attach(10);';
  
  var code = 'myservo.write('+value_degree+');\n';
  return code;
};

///////////////////////////////4wd_Car/////////////////////////////////////////////////
