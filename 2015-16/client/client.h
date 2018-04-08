const short EVENT_DELAY_TIME   = 40;
const short HOME_DELAY_TIME    = 10;

const short FRONT_LEFT_HIP_HOME_POS     = 6200;
const short FRONT_LEFT_KNEE_HOME_POS    = 5525;
const short FRONT_LEFT_ANKLE_HOME_POS   = 4450;
const short FRONT_RIGHT_HIP_HOME_POS    = 6350;
const short FRONT_RIGHT_KNEE_HOME_POS   = 6050;
const short FRONT_RIGHT_ANKLE_HOME_POS  = 6050;
const short BACK_RIGHT_HIP_HOME_POS     = 5225;
const short BACK_RIGHT_KNEE_HOME_POS    = 4675;
const short BACK_RIGHT_ANKLE_HOME_POS   = 6700;
const short BACK_LEFT_HIP_HOME_POS      = 6550;
const short BACK_LEFT_KNEE_HOME_POS     = 5550;
const short BACK_LEFT_ANKLE_HOME_POS    = 8375;
const short TURRET_PAN_HOME_POS         = 6000;
const short TURRET_TILT_HOME_POS        = 6050;

const short CREEP_ROTATE_ANGLE        =  1600;
const short CREEP_RAISE_KNEE_ANGLE    =  2500;
const short CREEP_RAISE_ANKLE_ANGLE   =  0;
const short CREEP_PUSH_ANKLE_ANGLE    =  900;
const short CREEP_PUSH_KNEE_ANGLE     = -200;
const short TURNING_V_ANGLE           =  1200;
const short TURNING_H_ANGLE           =  500;
const short TURRET_TILT_ANGLE         =  200;

const short TURRET_PAN_LEFT    = 5500;
const short TURRET_PAN_CENTER  = 6000;
const short TURRET_PAN_RIGHT   = 6500;

const short STANCE_LEN         = 15;
const short HOME_TO_CREEP_LEN  = 16;
const short CREEP_LEN          = 23;
const short CREEP_TO_HOME_LEN  = 16;
const short TURRET_V_LEN       = 6;
const short TURRET_H_LEN       = 8;
const short TURN_LEN           = 22;

enum stance_t {
    FRONT,
    BACK,
    RIGHT,
    LEFT,
    HOME
};

enum pservo_t {
    DELAY             = -1,
    FRONT_LEFT_HIP    = 0,
    FRONT_LEFT_KNEE   = 1,
    FRONT_LEFT_ANKLE  = 2,
    FRONT_RIGHT_HIP   = 3,
    FRONT_RIGHT_KNEE  = 4,
    FRONT_RIGHT_ANKLE = 5,
    BACK_RIGHT_HIP    = 6,
    BACK_RIGHT_KNEE   = 7,
    BACK_RIGHT_ANKLE  = 8,
    BACK_LEFT_HIP     = 9,
    BACK_LEFT_KNEE    = 10,
    BACK_LEFT_ANKLE   = 11,
    TURRET_PAN        = 12,
    TURRET_TILT       = 13,
    NUM_SERVOS        = 14
};

struct event_t {
    pservo_t servo;
    short value;
};

short HOME_POS[] = {
    [FRONT_LEFT_HIP]    = FRONT_LEFT_HIP_HOME_POS,
    [FRONT_LEFT_KNEE]   = FRONT_LEFT_KNEE_HOME_POS,
    [FRONT_LEFT_ANKLE]  = FRONT_LEFT_ANKLE_HOME_POS,
    [FRONT_RIGHT_HIP]   = FRONT_RIGHT_HIP_HOME_POS,
    [FRONT_RIGHT_KNEE]  = FRONT_RIGHT_KNEE_HOME_POS,
    [FRONT_RIGHT_ANKLE] = FRONT_RIGHT_ANKLE_HOME_POS,
    [BACK_RIGHT_HIP]    = BACK_RIGHT_HIP_HOME_POS,
    [BACK_RIGHT_KNEE]   = BACK_RIGHT_KNEE_HOME_POS,
    [BACK_RIGHT_ANKLE]  = BACK_RIGHT_ANKLE_HOME_POS,
    [BACK_LEFT_HIP]     = BACK_LEFT_HIP_HOME_POS,
    [BACK_LEFT_KNEE]    = BACK_LEFT_KNEE_HOME_POS,
    [BACK_LEFT_ANKLE]   = BACK_LEFT_ANKLE_HOME_POS,
    [TURRET_PAN]        = TURRET_PAN_HOME_POS,
    [TURRET_TILT]       = TURRET_TILT_HOME_POS
};

event_t HOME_STANCE[] = {
    {FRONT_RIGHT_HIP,   0},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    0},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,     0},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             HOME_DELAY_TIME}
};

event_t FRONT_STANCE[] = {
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {FRONT_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {BACK_RIGHT_HIP,     0},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {BACK_LEFT_HIP,      0},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t BACK_STANCE[] = {
    {FRONT_RIGHT_HIP,   0},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t LEFT_STANCE[] = {
    {FRONT_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {FRONT_LEFT_HIP,    0},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {BACK_RIGHT_HIP,    0},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {BACK_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t RIGHT_STANCE[] = {
    {FRONT_RIGHT_HIP,    0},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {FRONT_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {BACK_LEFT_HIP,      0},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {DELAY,              EVENT_DELAY_TIME}
};


event_t HOME_TO_CREEP_F[] = {
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t HOME_TO_CREEP_B[] = {
    {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   0},
    {BACK_LEFT_ANKLE,  0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,  0},
    {BACK_RIGHT_ANKLE, 0},
    {DELAY,            EVENT_DELAY_TIME}

};

event_t HOME_TO_CREEP_L[] = {
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t HOME_TO_CREEP_R[] = {
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t CREEP_FORWARD_FROM_R[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,     0},
    {FRONT_LEFT_HIP,    -CREEP_ROTATE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_FORWARD_FROM_L[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {FRONT_RIGHT_HIP,   CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t CREEP_BACKWARD_FROM_R[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   0},
    {BACK_LEFT_HIP,     CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_BACKWARD_FROM_L[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_PUSH_KNEE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {BACK_RIGHT_HIP,    -CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME}
};

event_t CREEP_LEFT_FROM_F[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,    CREEP_PUSH_KNEE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {BACK_LEFT_HIP,     -CREEP_ROTATE_ANGLE},
    {BACK_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_LEFT_KNEE,    0},
    {FRONT_LEFT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,   CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,     CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,    0},
    {BACK_RIGHT_ANKLE,   0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_LEFT_FROM_B[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_LEFT_KNEE,    CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,    CREEP_PUSH_KNEE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_LEFT_KNEE,    0},
    {BACK_LEFT_ANKLE,   0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_RIGHT_FROM_F[] = {
    {TURRET_PAN,         0},
    {TURRET_TILT,        0},
    {FRONT_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,    0},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_RIGHT_ANKLE, -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,     0},
    {BACK_RIGHT_HIP,     CREEP_ROTATE_ANGLE},
    {BACK_LEFT_ANKLE,   -CREEP_PUSH_ANKLE_ANGLE},
    {FRONT_RIGHT_KNEE,   0},
    {FRONT_RIGHT_ANKLE,  0},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,    CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,      -CREEP_ROTATE_ANGLE},
    {DELAY,              EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,     0},
    {BACK_LEFT_ANKLE,    0},
    {DELAY,              EVENT_DELAY_TIME}

};

event_t CREEP_RIGHT_FROM_B[] = {
    {TURRET_PAN,        0},
    {TURRET_TILT,       0},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_PUSH_KNEE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,     0},
    {FRONT_RIGHT_HIP,   -CREEP_ROTATE_ANGLE},
    {FRONT_LEFT_ANKLE,  -CREEP_PUSH_ANKLE_ANGLE},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,    CREEP_ROTATE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,   0},
    {FRONT_LEFT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}

};

event_t CREEP_F_TO_HOME[] = {
  {FRONT_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
  {FRONT_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_LEFT_HIP,    0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_LEFT_KNEE,   0},
  {FRONT_LEFT_ANKLE,  0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
  {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_HIP,   0},
  {DELAY,             EVENT_DELAY_TIME},
  {FRONT_RIGHT_KNEE,  0},
  {FRONT_RIGHT_ANKLE, 0},
  {DELAY,             EVENT_DELAY_TIME}


};

event_t CREEP_B_TO_HOME[] = {
  {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
  {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_LEFT_HIP,    0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_LEFT_KNEE,   0},
  {BACK_LEFT_ANKLE,  0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
  {BACK_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_HIP,   0},
  {DELAY,            EVENT_DELAY_TIME},
  {BACK_RIGHT_KNEE,  0},
  {BACK_RIGHT_ANKLE, 0},
  {DELAY,            EVENT_DELAY_TIME}

};

event_t CREEP_L_TO_HOME[] = {
    {FRONT_LEFT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_LEFT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE,  0},
    {FRONT_LEFT_ANKLE, 0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_LEFT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_HIP,    0},
    {DELAY,            EVENT_DELAY_TIME},
    {BACK_LEFT_KNEE,   0},
    {BACK_LEFT_ANKLE,  0},
    {DELAY,            EVENT_DELAY_TIME}
};

event_t CREEP_R_TO_HOME[] = {
    {FRONT_RIGHT_KNEE,  CREEP_RAISE_KNEE_ANGLE},
    {FRONT_RIGHT_ANKLE, CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,   0},
    {DELAY,             EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE,  0},
    {FRONT_RIGHT_ANKLE, 0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   CREEP_RAISE_KNEE_ANGLE},
    {BACK_RIGHT_ANKLE,  CREEP_RAISE_ANKLE_ANGLE},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_HIP,    0},
    {DELAY,             EVENT_DELAY_TIME},
    {BACK_RIGHT_KNEE,   0},
    {BACK_RIGHT_ANKLE,  0},
    {DELAY,             EVENT_DELAY_TIME}
};

event_t TURRET_V[] = {
    {TURRET_TILT,   700},
    {DELAY,         1000},
    {TURRET_TILT,  -700},
    {DELAY,         1000},
    {TURRET_TILT,   0},
    {DELAY,         1000}
};

event_t TURRET_H[] = {
    {TURRET_PAN,   1000},
    {DELAY,        300},
    {TURRET_PAN,  -1000},
    {DELAY,        600},
    {TURRET_PAN,   1000},
    {DELAY,        355},
    {TURRET_PAN,   0},
    {DELAY,        300}
};

event_t TURN_L[] = {
    {FRONT_LEFT_KNEE, TURNING_V_ANGLE},
    {BACK_RIGHT_KNEE, TURNING_V_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  -TURNING_H_ANGLE},
    {BACK_RIGHT_HIP,  -TURNING_H_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE, 0},
    {BACK_RIGHT_KNEE, 0},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  0},
    {BACK_RIGHT_HIP,  0},

    {FRONT_RIGHT_KNEE, TURNING_V_ANGLE},
    {BACK_LEFT_KNEE,   TURNING_V_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  -TURNING_H_ANGLE},
    {BACK_LEFT_HIP,    -TURNING_H_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE, 0},
    {BACK_LEFT_KNEE,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  0},
    {BACK_LEFT_HIP,    0}
};

event_t TURN_R[] = {
    {FRONT_LEFT_KNEE, TURNING_V_ANGLE},
    {BACK_RIGHT_KNEE, TURNING_V_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  TURNING_H_ANGLE},
    {BACK_RIGHT_HIP,  TURNING_H_ANGLE},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_KNEE, 0},
    {BACK_RIGHT_KNEE, 0},
    {DELAY,           EVENT_DELAY_TIME},
    {FRONT_LEFT_HIP,  0},
    {BACK_RIGHT_HIP,  0},

    {FRONT_RIGHT_KNEE, TURNING_V_ANGLE},
    {BACK_LEFT_KNEE,   TURNING_V_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  TURNING_H_ANGLE},
    {BACK_LEFT_HIP,    TURNING_H_ANGLE},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_KNEE, 0},
    {BACK_LEFT_KNEE,   0},
    {DELAY,            EVENT_DELAY_TIME},
    {FRONT_RIGHT_HIP,  0},
    {BACK_LEFT_HIP,    0}
};
