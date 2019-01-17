#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÍõÎå",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":               "Ð¡··",
                "quest_type":           "É±",
                "time":                 900,
                "score" :               8
        ]),        
        ([      "quest":               "ÕÅÂè",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               10
        ]), 
        ([      "quest":               "´å¹Ã",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),    
        ([      "quest":               "¹Ù±ø",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               9
        ]),          
        ([      "quest":               "µÀÍ¯",
                "quest_type":           "É±",
                "time":                 800,
                "score" :               6
        ]),       
         ([      "quest":               "ÓÎ¿Í",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
       ([      "quest":                "ÍÃÈâ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               6
        ]),
       ([      "quest":                "âÎ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               5
        ]),

        ([      "quest":                "Ìú¼×",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),       
          ([      "quest":                "Á·Îä³¡",
                  "quest_type":           "É¨",
                "time":                 400,
                "score" :               7
        ]),  
          ([      "quest":                "±øÆ÷·¿",
                  "quest_type":           "É¨",
                "time":                 500,
                "score" :               8
        ]),  
          ([      "quest":                "É½ºéÆÙ²¼",
                  "quest_type":           "É¨",
                "time":                 470,
                "score" :               9
        ]),  
          ([      "quest":                "ÓñÈªÔº",
                  "quest_type":           "É¨",
                "time":                 430,
                "score" :               10
        ]),  

        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               4
        ]),
          ([      "quest":                "¿ÍÌü",
                  "quest_type":           "É¨",
                "time":                 650,
                "score" :               9
        ]),
        ([      "quest":                "ÂÛÓï",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               8
        ]),  
        ([      "quest":                "Ðå»¨Ð¬",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               9
        ]),  
        ([      "quest":                "ÉßÈâ",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               10
        ]),  
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
