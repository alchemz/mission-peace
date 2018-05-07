#include <iostream>
using namespace std;

struct Rectangle{
  double x1;
  double y1;
  double x2;
  double y2;
};

int between(double d1, double d2, double d3){
  if(d1<d2)
    return (d1<=d3 && d3<=d2);
  else
    return (d2<=d3 && d3<=d1);    
}

bool overlap(Rectangle a, Rectangle b){
      /* 1 */
    if (between(a.x1, a.x2, b.x1) && between(a.y1, a.y2, b.y1))
        return true;
    if (between(a.x1, a.x2, b.x2) && between(a.y1, a.y2, b.y2))
        return true;
    if (between(a.x1, a.x2, b.x1) && between(a.y1, a.y2, b.y2))
        return true;
    if (between(a.x1, a.x2, b.x2) && between(a.y1, a.y2, b.y1))
        return true;

    /* 2 */
    if (between(b.x1, b.x2, a.x1) && between(b.y1, b.y2, a.y1))
        return true;
    if (between(b.x1, b.x2, a.x2) && between(b.y1, b.y2, a.y2))
        return true; 

    /* 3 */
    if ( (between(a.y1, a.y2, b.y1) && between(a.y1, a.y2, b.y2))
      && (between(b.x1, b.x2, a.x1) && between(b.x1, b.x2, a.x2)) )
        return true;

    /* 4 */
    if ( (between(a.x1, a.x2, b.x1) && between(a.x1, a.x2, b.x2))
      && (between(b.y1, b.y2, a.y1) && between(b.y1, b.y2, a.y2)) )
        return true;
  
    return false;
}

int main(){
  Rectangle a = {0.0, 0.0, 9.0, 9.0};
  // Rectangle b= {10.0, 10.0, 19, 19};
  
  // Rectangle b= {8.0, 8.0, 19, 19};
  // Rectangle b= {-1.0, 5.0, 10, 10};
  // Rectangle b= {-1.0, -1.0, 10, 10};
  
  /*3*/
  Rectangle b = {2.0, -2.0, 5.0, 12.0};

  /*4*/
  // Rectangle b = {-12.0, 2.0, 15.0, 3.0};
  
  bool flag = false;  
  flag = overlap(a, b);  
  if(flag)
    cout<<"two rectangles are overlapped";
  else
    cout<<"two rectangles are not overlapped";
  
  return 0;
}

/*

 * 几种重叠的情况

 *

 * 1. B 至少有一个顶点在 A 的内部

 *     -----------------

 *     |A              |

 *     |               |

 *     |           ------------

 *     |           |   |      |

 *     |           |   |      |

 *     ------------|----      |

 *                 |         B|

 *                 ------------

 *

 * 2. 如果 B 的顶点都在 A 的外部

 *    重叠的条件是 A 的对角顶点至少有一个在 B 的内部

 * 2.1

 * ----------------------------

 * |                          |

 * |   -----------------      |

 * |   |A              |      |

 * |   |               |     B|

 * ----------------------------

 *     |               |       

 *     |               |       

 *     -----------------       

 *

 * 2.2

 * ----------------------------

 * |                          |

 * |   -----------------      |

 * |   |A              |      |

 * |   |               |      |

 * |   |               |      |

 * |   |               |      |

 * |   -----------------     B|

 * ----------------------------

 *

 *  3. 十字交叉情况1

 *       ----------

 *       |A       |

 *       |        |

 * ----------------------------

 * |     |        |           |

 * |     |        |          B|

 * ----------------------------

 *       |        |

 *       |        |

 *       ----------

 *

 *  4. 十字交叉情况2

 *       ----------

 *       |        |

 *       |        |

 * ----------------------------

 * |A    |        |           |

 * |     |        |           |

 * ----------------------------

 *       |        |

 *       |       B|

 *       ----------

 */
