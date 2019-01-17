
//modified by tlang for /cmds/std/look.c
//this is for descripe a person's bellicosit for look.c
nosave string *all_exits = ({
    "east",
    "south",
    "west",
    "north",
    "eastup",
    "southup",
    "westup",
    "northup",
    "eastdown",
    "southdown",
    "westdown",
    "northdown",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "enter",
    "out",
});

string *bel_msg_male1 = ({
        "Á³ÉÏÂ¶³öÁİÙıµÄÉ±»ú¡£",
        "°º×ÅÍ·£¬ÀäÀäµØÈÃÈË²»¸ÒÇ×½ü¡£",
});

string *bel_msg_male2 = ({
        "Ã¼Í·½ôËø£¬ËÆºõÓĞĞ©ĞÄÊÂ¡£",
        "Á³ÉÏ¸¡ÏÖ³öÒ»¹ÉÅ°Æø¡£",
});

string *bel_msg_male3 = ({
        "Á³ÉÏÂ¶³ö²ÓÀÃµÄĞ¦Èİ¡£",
        "Á³ÉÏÂ¶³öÓä¿ìµÄÎ¢Ğ¦¡£",
});

string *bel_msg_female1 = ({
        "Àä±ù±ùµØÈÃÈË²»¸ÒÇ×½ü¡£",
        "·ÛÁ³ÖĞÍ¸³öÒ»Ğ©É±Æø¡£",
});

string *bel_msg_female2 = ({
        "Ã¼Í·Çáõ¾£¬ËÆºõÓĞĞ©ĞÄÊÂ¡£",
        "ÓĞĞ©²»´ó¸ßĞË¡£",
});

string *bel_msg_female3 = ({
        "ÌìÕæµØĞ¦×Å¡£",
        "Óä¿ìµØĞ¦×Å¡£",
        "¿´ÉÏÈ¥ÌìÕæÎŞĞ°¡£",
});

string *bel_msg_nomale1 = ({
        "ËÆºõÓĞÊ²Ã´ĞÄÊÂ¡£",
        "ÑÛ¹âµ½´¦ËÑË÷£¬²»ÖªµÀÊÇÔÚËÑÑ°Ê²Ã´¡£",
});

string *bel_msg_nomale2 = ({
        "ÇáÉùÌ¾Ï¢£¬ÑÛ¹âÖĞÓĞÖÖÄªÃûµÄÓÇÉË¡£",
        "Ä¿¹âÆæÌØ£¬Ò²²»ÖªµÀÊÇÖĞÊ²Ã´Ğ°ÁË¡£",
});

string *bel_msg_nomale3 = ({
        "Â¶³öÒ»ÖÖÄªÃûÆäÃîµÄÆæÒì±íÇé¡£",
        "ĞË·ÜÄªÃû£¬Ò²²»ÖªµÀÎªÊ²Ã´¡£",
        "Â¶³öÒ»ÖÖ²»Õı³£µÄ±íÇé¡£",
});

string bel_status_msg(int shen,string gender)
{
        if ( gender == "ÄĞĞÔ" ) {
                if ( shen < -500 )
                return ( bel_msg_male1[random(sizeof(bel_msg_male1))]);
                else if ( shen < 0 )
                return ( bel_msg_male2[random(sizeof(bel_msg_male2))]);
                else if ( shen>=0 )
                return ( bel_msg_male3[random(sizeof(bel_msg_male3))]);
        }
        if ( gender == "Å®ĞÔ" ) {
                if ( shen>=-500 )
                return ( bel_msg_female1[random(sizeof(bel_msg_female1))]);
                else if ( shen< 0)
                     return ( bel_msg_female2[random(sizeof(bel_msg_female2))]);
                else if ( shen>=0 )
                return ( bel_msg_female3[random(sizeof(bel_msg_female3))]);
        }
       else {
                if ( shen>=-500 )
                return ( bel_msg_nomale1[random(sizeof(bel_msg_nomale1))]);
                else if ( shen< 0 )
                        return ( bel_msg_nomale2[random(sizeof(bel_msg_nomale2))]);
                else if ( shen>=0 )
                return ( bel_msg_nomale3[random(sizeof(bel_msg_nomale3))]);
        }
}

//this is for descripe a person's per.
string *per_msg_male1 = ({
        "Ó¢¿¡äìÈ÷,·ç¶Èôæôæ£¬ÆøËÀÅË°²£¬ĞßËÀËÎÓñ¡£" ,
        "ÏàÃ²³öÖÚ,ÃæÄ¿¿¡ÀÊ£¬ĞÇÄ¿º¬Çé£¬½£Ã¼Â¶Íş¡£" ,
});

string *per_msg_male2 = ({
        "Ó¢¿¡äìÈ÷,·ç¶Èôæôæ¡£",
        "ÏàÃ²³öÖÚ,ÃæÄ¿¿¡ÀÊ¡£",
});
string *per_msg_male3 = ({
        "ÏàÃ²Æ½Æ½£¬Ã»Ê²÷áºÃ¿´µÄ¡£",
        "³¤µÃÄèÄèµÄ£¬Ò»¸±ÎŞ¾«´ò²ÉµÄÄ£Ñù¡£",
        "ÏàÃ²Ğ×¶ñ£¬ÂúÁ³ºáÈâ¡£",
});
string *per_msg_female1 = ({
        "ÈİÉ«ĞãÀö£¬·ç×Ë´ÂÔ¼£¬ÓĞÒ»¶ÎËµ²»³öµÄ·çÁ÷ÌåÌ¬¡£",
        "³¤·¢ÈçÔÆ£¬¼¡·ôÊ¤Ñ©£¬²»ÖªÇãµ¹ÁË¶àÉÙÓ¢ĞÛºÀ½Ü¡£ ",
        "ÇÎÁ³Éú´º£¬ÃîÄ¿º¬Çé£¬ÇáÇáÒ»Ğ¦£¬²»¾õÈÃÈËâñÈ»ĞÄ¶¯¡£",
        "·çÇéÍòÖÖ£¬³ş³ş¶¯ÈË£¬µ±ÕæÊÇÎÒ¼
ûÓÌÁ¯¡£",
});

string *per_msg_female2 = ({
        "ÈİÉ«ĞãÀö£¬·ç×Ë´ÂÔ¼£¬ÓĞÒ»¶ÎËµ²»³öµÄ·çÁ÷ÌåÌ¬¡£" ,
        "³¤·¢ÈçÔÆ£¬¼¡·ôÊ¤Ñ©£¬²»ÖªÇãµ¹ÁË¶àÉÙÓ¢ĞÛºÀ½Ü¡£ ",
        "ÇÎÁ³Éú´º£¬ÃîÄ¿º¬Çé£¬ÇáÇáÒ»Ğ¦£¬²»¾õÈÃÈËâñÈ»ĞÄ¶¯¡£",
        "·çÇéÍòÖÖ£¬³ş³ş¶¯ÈË£¬µ±ÕæÊÇÎÒ¼ûÓÌÁ¯¡£ ",
});

string *per_msg_female3 = ({
        "ËäËã²»ÉÏ¾øÊÀ¼ÑÈË£¬Ò²ÆÄÓĞ¼¸·İ×ËÉ«¡£ ",
        "³¤µÃ»¹²»´í£¬ÆÄÓĞ¼¸·İ×ËÉ«¡£  ",
});

string *per_msg_nomale1 = ({
        "³¤·¢Åû¼ç£¬¼¡·ô¶¯ÈË£¬Ò²¿´²»³öÊÇÄĞÊÇÅ®¡£" ,
        "Ã¼ÇåÄ¿Ğã£¬ÓĞÈı·ÖÏóËÎÓñ£¬È´ÓĞÆß·ÖÏó·ÉÑà¡£ ",
});
string *per_msg_nomale2 = ({
        "ÃæÄ¿ÇåĞã£¬Ö»ÊÇÒşÒşÂ¶³öÒ»ÖĞÅ®¶ùµÄÖ¬·ÛÆø¡£",
        "¿´ÉÏÈ¥Ò²²»ÖªµÀ³¤µÄÔõÑù£¬µ«×ì½ÇµÄĞ¦È´ÈÃÄĞÈËºÍÅ®ÈË¶¼ÓĞĞ©ĞÄ¶¯¡£ ",
});

string *per_msg_nomale3 = ({
        "³¤µÃ»¹¿ÉÒÔ£¬Ö»ÊÇ¼ÈÃ»ÓĞÄĞÈËµÄ´Öáî£¬ÓÖÈ±ÉÙÅ®×ÓµÄÎÂÈá¡£ ",
        "±¾À´»¹ÓĞµã´ÖáîÃÀ£¬µ«ÏÖÔÚÈ´ÓĞĞ©Å¤Äó×÷Ì¬£¬²»ÄĞ²»Å®¡£",
});


string per_status_msg(int per, string gender)
{
        if ( gender == "ÄĞĞÔ" ) {
                if ( per>=25 )
                return ( per_msg_male1[random(sizeof(per_msg_male1))]);
                else if ( per>=20 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))]);
                else if ( per<20 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))]);
    }
        if ( gender == "Å®ĞÔ" ) {
                if ( per>=25 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per<20 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))]);

    }
        else {
                if ( per>=25 )
                return ( per_msg_nomale1[random(sizeof(per_msg_nomale1))]);
                else if ( per>=20 )
                return ( per_msg_nomale2[random(sizeof(per_msg_nomale2))]);
                else if ( per<20 )
                return ( per_msg_nomale3[random(sizeof(per_msg_nomale3))]);
    }
}
string *look_level_boy = ({
 BLU "Ã¼ÍáÑÛĞ±£¬ğøÍ·Ñ¢½Å£¬²»ÏóÈËÑù" NOR,
 BLU "ßÚÑÀßÖ×ì£¬ºÚÈç¹øµ×£¬Ææ³óÎŞ±È" NOR,
 BLU "ÃæÈç½ÛÆ¤£¬Í·Ö×ÈçÖí£¬ÈÃÈË²»ÏëÔÙ¿´µÚ¶şÑÛ" NOR,
 HIB "ÔôÃ¼ÊóÑÛ£¬Éí¸ßÈı³ß£¬ÍğÈôºï×´" NOR,
 HIB "·ÊÍ·´ó¶ú£¬¸¹Ô²Èç¹Ä£¬ÊÖ½Å¶Ì´Ö£¬ÁîÈË·¢Ğ¦" NOR,
 NOR "Ãæ¼Õ°¼Ïİ£¬Êİ¹ÇÁæØê£¬¿ÉÁ¯¿ÉÌ¾" NOR,
 NOR "ÉµÍ·ÉµÄÔ£¬³Õ³Õº©º©£¬¿´À´µ¹Ò²ÀÏÊµ" NOR,
 NOR "ÏàÃ²Æ½Æ½£¬²»»á¸øÈËÁôÏÂÊ²Ã´Ó¡Ïó" NOR,
 YEL "°ò´óÑüÔ²£¬ÂúÁ³ºáÈâ£¬¶ñĞÎ¶ñÏà" NOR,
 YEL "ÑüÔ²±³ºñ£¬ÃæÀ«¿Ú·½£¬¹Ç¸ñ²»·²" NOR,
 RED "Ã¼Ä¿ÇåĞã£¬¶ËÕı´ó·½£¬Ò»±íÈË²Å" NOR,
 RED "Ë«ÑÛ¹â»ªÓ¨Èó£¬Í¸³öÉãÈËĞÄÆÇµÄ¹âÃ¢" NOR,
 HIY "¾Ù¶¯ÈçĞĞÔÆÓÎË®£¬¶ÀÔÌ·çÇé£¬ÎüÒıËùÓĞÒìĞÔÄ¿¹â" NOR,
 HIY "Ë«Ä¿ÈçĞÇ£¬Ã¼ÉÒ´«Çé£¬Ëù¼ûÕßÎŞ²»ÎªÖ®ĞÄ¶¯" NOR,
 HIR "·ÛÃæÖì´½£¬Éí×Ë¿¡ÇÎ£¬¾ÙÖ¹·çÁ÷ÎŞÏŞ" NOR,
 HIR "·áÉñÈçÓñ£¬Ä¿ËÆÀÊĞÇ£¬ÁîÈË¹ıÄ¿ÄÑÍü" NOR,
 MAG "ÃæÈçÃÀÓñ£¬·Û×±Óñ×Á£¬¿¡ÃÀ²»·²" NOR,
 MAG "Æ®Òİ³ö³¾£¬äìÈ÷¾øÂ×" NOR,
 MAG "·áÉñ¿¡ÀÊ£¬³¤ÉíÓñÁ¢£¬ÍğÈçÓñÊ÷ÁÙ·ç" NOR,
 HIM "ÉñÇåÆøË¬£¬¹Ç¸ñÇåÆæ£¬ÍğÈôÏÉÈË" NOR,
 HIM "Ò»ÅÉÉñÈËÆø¶È£¬ÏÉ·çµÀ¹Ç£¬¾ÙÖ¹³ö³¾" NOR,
});

string *look_level_girl = ({
  BLU "³óÈçÎŞÑÎ£¬×´ÈçÒ¹²æ" NOR,
  BLU "Íá±ÇĞ±ÑÛ£¬Á³É«»Ò°Ü£¬Ö±Èç¹í¹ÖÒ»°ã" NOR,
  BLU "°Ë×ÖÃ¼£¬Èı½ÇÑÛ£¬¼¦Æ¤»Æ·¢£¬ÈÃÈËÒ»¼û¾ÍÏëÍÂ" NOR,
  HIB "ÑÛĞ¡Èç¶¹£¬Ã¼Ã«Ï¡Êè£¬ÊÖÈçºï×¦£¬²»³ÉÈËÑù" NOR,
  HIB "Ò»×ì´ó±©ÑÀ£¬ÈÃÈËÒ»¿´¾ÍÃ»ºÃ¸Ğ" NOR,
  NOR "ÂúÁ³¸í´ñ£¬Æ¤É«´ÖºÚ£¬³óÂª²»¿°" NOR,
  NOR "¸É»Æ¿İÊİ£¬Á³É«À°»Æ£¬ºÁÎŞÅ®ÈËÎ¶" NOR,
  YEL "Éí²ÄÊİĞ¡£¬¼¡·ôÎŞ¹â£¬Á½ÑÛÎŞÉñ" NOR,
  YEL "Ëä²»±êÖÂ£¬µ¹Ò²°×¾»£¬ÓĞĞ©¶¯ÈËÖ®´¦" NOR,
  RED "¼¡·ôÎ¢·á£¬ÑÅµ­ÎÂÍğ£¬ÇåĞÂ¿ÉÈË" NOR,
  RED "ÏÊÑŞåûÃÄ£¬¼¡·ôÓ¨Í¸£¬ÒıÈËåÚË¼" NOR,
  HIR "½¿Ğ¡Ááçç£¬ÍğÈç·ÉÑàÔÙÊÀ£¬³ş³ş¶¯ÈË" NOR,
  HIR "ÈùÄıĞÂÀó£¬¼¡·ôÊ¤Ñ©£¬Ä¿ÈôÇïË®" NOR,
  HIW "·ÛÄÛ°×ÖÁ£¬ÈçÉÖÒ©ÁıÑÌ£¬ÎíÀï¿´»¨" NOR,
  HIW "·áĞØÏ¸Ñü£¬Ñıæ¬¶à×Ë£¬ÈÃÈËÒ»¿´¾ÍĞÄÌø²»ÒÑ" NOR,
  MAG "½¿Èô´º»¨£¬ÃÄÈçÇïÔÂ£¬ÕæµÄÄÜ³ÁÓãÂäÑã" NOR,
  MAG "Ã¼Ä¿Èç»­£¬¼¡·ôÊ¤Ñ©£¬Õæ¿ÉÎ½±ÕÔÂĞß»¨" NOR,
  MAG "ÆøÖÊÃÀÈçÀ¼£¬²Å»ªğ¥±ÈÉ½£¬ÁîÈË¼ûÖ®ÍüË×" NOR,
  HIM "²ÓÈôÃ÷Ï¼£¬±¦ÈóÈçÓñ£¬»ĞÈçÉñåúÏÉ×Ó" NOR,
  HIM "ÃÀÈôÌìÏÉ£¬²»Õ´Ò»Ë¿ÑÌ³¾" NOR,
  HIM "ÍğÈç"+HIW+"Óñµñ±ùËÜ"+HIM+"£¬ËÆÃÎËÆ»Ã£¬ÒÑ²»ÔÙÊÇ·²¼äÈËÎï" NOR,
});
  
 string *tough_level_desc = ({
        BLU "²»¿°Ò»»÷" NOR,
        BLU "ºÁ²»×ãÂÇ" NOR,
        BLU "²»×ã¹Ò³İ" NOR,
        BLU "³õÑ§Õ§Á·" NOR,
        HIB "³õ¿úÃÅ¾¶" NOR,
        HIB "ÂÔÖªÒ»¶ş" NOR,
        HIB "ÆÕÆÕÍ¨Í¨" NOR,
        HIB "Æ½Æ½µ­µ­" NOR,
        HIB "Æ½µ­ÎŞÆæ" NOR,
        HIB "´ÖÍ¨Æ¤Ã«" NOR,
        HIB "°ëÉú²»Êì" NOR,
        HIB "ÂíÂí»¢»¢" NOR,
        HIB "ÂÔÓĞĞ¡³É" NOR,
        HIB "ÒÑÓĞĞ¡³É" NOR,
        HIB "¼İÇá¾ÍÊì" NOR,
        CYN "ĞÄÁìÉñ»á" NOR,
        CYN "ÁËÈ»ì¶ĞØ" NOR,
        CYN "ÂÔÓĞ´ó³É" NOR,
        CYN "ÒÑÓĞ´ó³É" NOR,
        CYN "»íÈ»¹áÍ¨" NOR,
        CYN "³öÀà°ÎİÍ" NOR,
        CYN "ÎŞ¿ÉÆ¥µĞ" NOR,
        CYN "¼¼¹ÚÈºĞÛ" NOR,
        CYN "ÉñºõÆä¼¼" NOR,
        CYN "³öÉñÈë»¯" NOR,
        CYN "°ÁÊÓÈºĞÛ" NOR,
        HIC "µÇ·åÔì¼«" NOR,
        HIC "ËùÏòÅûÃÒ" NOR,
        HIC "Ò»´ú×ÚÊ¦" NOR,
        HIC "Éñ¹¦¸ÇÊÀ" NOR,
        HIC "¾ÙÊÀÎŞË«" NOR,
        HIC "¾ªÊÀº§Ë×" NOR,
        HIC "Õğ¹Åîå½ñ" NOR,
        HIC "Éî²Ø²»Â¶" NOR,
        HIR "Éî²»¿É²â" NOR
});
string *heavy_level_desc= ({
        "¼«Çá",
        "ºÜÇá",
        "²»ÖØ",
        "²»Çá",
        "ºÜÖØ",
        "¼«ÖØ"
}); 
