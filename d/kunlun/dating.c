// room: /kunlun/dating.c

inherit ROOM;



void create()

{

        set("short", "´óÌü");

        set("long", @LONG

ÕâÊÇÈıÊ¥ÌÃµÄ´óÌü£¬ÀúÀ´ÊÇÕÆÃÅÈËÕıÊ½´ı¿ÍµÄµØ·½£¬¹Ê´Ë³ÂÉè×¯ÖØ½÷ÑÏ¡£¬

ÕıÖĞÓĞÁ½ÕÅÌ«Ê¦ÒÎ£¬ÊÇÕÆÃÅÈË¼°·òÈËµÄ×ùÎ»¡£ÊÒÄÚÒ»³¾²»È¾, Òì³£Õû½à¡£¼¸

ÃûµÜ×ÓµÍÍ·ÊÌÁ¢ÔÚÒ»ÅÔ£¬¶«Î÷Á½±ß¸÷ÓĞÒ»¸ö²àÌü£¬ÌüÉÏ¸ß¸ßµÄĞüÒ»·ù¾Ş´óµÄ

ØÒ¶î (bian)¡£

LONG

        );

        set("item_desc", ([

                "bian"    : "ÉÏÊéËÄ¸ö´ó×Ö¡°ÇÙ ½£ ÎŞ Ë«¡±\n",

        ]));

        set("exits", ([

                "south" : __DIR__"zhongt",

                "north" : __DIR__"zoul_5",

                "west" : __DIR__"ceting_w",

                "east" : __DIR__"ceting_e",

        ]));



        setup();

        replace_program(ROOM);

}



