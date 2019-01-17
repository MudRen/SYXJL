#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÍõÎå",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "°¢×Ï",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "ÊØËÂÉ®±ø",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "É®¹÷",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "¿àº®Â¥Èý²ã",
                "quest_type":           "É¨",
                "time":                 240,
                "score" :               6
        ]),
        ([      "quest":                "ºóÔº",
                "quest_type":           "É¨",
                "time":                 240,
                "score" :               8
        ]),
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ìú¼×",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "¸ÖÕÈ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "ÀîÄª³î",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               9
        ]),
        ([      "quest":                "¿àº®Â¥¶þ²ã",
                "quest_type":           "É¨",
                "time":                 240,
                "score" :               8
        ]),
        ([      "quest":                "¾ªÉñ·å",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               9
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

