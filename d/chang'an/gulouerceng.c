inherit ROOM;
void create()
{
        set("short", "¹ÄÂ¥¶ş²ã");
        set("long", @LONG
ÕâÀï¾ÍÊÇ¹ÄÂ¥¶şÂ¥ÁË¡£µÚ¶ş²ãÂ¥ÉÏ¸´ÂÌÁğÁ§Íß£¬ÖØéÜĞªÉ½¶¥£»ÃæÀ«¸÷
ÎªÆß¼ä£¬½øÉî¾ùÎªÈı¼ä£¬ËÄÖÜÁíÓĞ×ßÀÈ¡£Ã¿²ãÕıÃæÊ®¸ùºìÖù£¬¾Å¸ö¿ª¼ä¡£
±±Éè¾Ş¹ÄÒ»Ãæ£¬»÷¹ÄÎªÈ«ÊĞ¾ÓÃñ±¨Ê±£¬¹ÄÂ¥Òò´ËµÃÃû¡£¡
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"gulou",
                "up"    : __DIR__"gulousanceng",                             
        ]));
        set("objects", ([
                __DIR__"npc/laohan" : 1,

        ]));


        setup();
}
int valid_leave(object me, string dir)
{

        if ( !me->query_temp("up") && dir == "up" )
                return notify_fail("ÀÏººÉìÊÖÒ»À¹£º¡°ÕâÀï¿ÉÊÇ¹Ù¼ÒµÄµØ·½£¬ÄãÏëÕâÑùËæ±ã¾Í½øÈ¥À²£¡¡±\n");

        return ::valid_leave(me, dir);
}
