#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "¡º¶ëáÒÉ½ÂÃÓÎÍ¼¡»" NOR, ({ "luyou tu", "tu" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ÕÅ");
                set("long",@LONG         
                        ½ð¶¥        ¾²ÐÞâÖ
                         |            |
                        ÔÆº£  ºóÉ½  É½µÀ
                          \     |    / \
          ¾ÅÀÏ¶´-Ð¡¾¶    É½µÀ ºóÉ½ É½µÀ É½µÀ-Ò©Íõ¶´
                   \     /   \  | /   \
                  Ð¡¾¶-Ð¡¾¶   É½µÀ   Ð¡Ïª
                                |      |
Éß¿ß¾¡Í·                 ÇÞÊÒ ºóÃÅ   Ð¡Ïª
   |                      |     |       \
  Éß¿ß              ÇÞÊÒ-»¨Ô°-ºóÔ°     ÆÙ²¼
   |                      |     |        |
Éß¿ßÈË¿Ú                 ÇÞÊÒ Ð¡µÀ     É½¶´-É½¶´
   |                            |
 Ð¡µÀ-Ð¡µÀ-±±²àÃÅ-±±ÀÈ--±±ÀÈ--ÉñµÆ¸ó--±±ÀÈ--±±ÀÈ-ÉÅ·¿-»ï·¿
                    |           |            |
             ìø·¿-Î÷ÀÈ-ìø·¿    ºóµî    ìø·¿-¶«ÀÈ-Ïá·¿
                    |           |            |
        Æº   ìø·¿-Î÷ÀÈ-ìø·¿   ½ÓÒýµî   ìø·¿-¶«ÀÈ-Ïá·¿      ²Ø¾­Â¥
        |           |           |            |            /
      Ð¡µÀ-Î÷²àÃÅ-Î÷ÀÈ-Î÷ÀÈ-Ç§·ðâÖ´óµî-¶«ÀÈ-¶«ÀÈ-¶«²àÃÅ-¹éÔÆ¸ó
       /            |           |            |
      Æº     ìø·¿-Î÷ÀÈ-ìø·¿   ÅþÂ¬µî   ìø·¿-¶«ÀÈ-Ïá·¿
                    |           |            |
             ìø·¿-Î÷ÀÈ-ìø·¿   ÎÄÊâµî   ìø·¿-¶«ÀÈ-Ïá·¿
                                |
                            Ç§·ðâÖ´óÃÅ-ÇåÒô¸ó-ÍòÄêâÖ
                                         |
                                       ÉñË®¸ó
                                         | 
                                        Ê¯½×          
                                         |
                     å                É½ÃÅµî        
                                         |         
                     Ò           ÓñÅ®·å-É½ÃÅ                         
                                     |  
               ±£¹úËÂ´óµî  ÂÞ·åÉ½  Ê¯·»                                
                    |        |       |               
         ·ï»ËÌ¨-±£¹úËÂ´óÃÅ-·ü»¢ËÂ-½âÍÑÇÅ                
                    |
                  ¹ã³¡
                    |
                 ½â½£Ê¯                                  
                    |
                  Ê¯½×          
LONG );


		set("value", 50);
		set("material", "paper");
	}
	setup();
}
