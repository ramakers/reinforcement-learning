#include</usr/include/boost/gil/gil_all.hpp>

using namespace boost::gil;

void x_gradient(const gray8c_view_t& src,
                const gray8s_view_t& dst)
{
  for(int y=1;y<src.height()-1; ++y){
    gray8c_view_t::x_iterator src1_it = src.row_begin(y-1);
    gray8s_view_t::x_iterator src2_it = dst.row_begin(y+1);
    gray8s_view_t::x_iterator dst_it = dst.row_begin(y);
    
    for(int x=0;x<src.width(); ++x){
      *dst_it =((*src2_it) - (*src1_it))/ 2;
      ++dst_it; ++src1_it; ++src2_it;
    }
  
  }
}

void x_gradient(const gray8c_view_t& src,
                const gray8s_view_t& dst)
{
  gray8c_view_t::xy_locator src_loc = src.xy_at(0,1);
  
  for(int y=1;y<src.height()-1; ++y){
    gray8s_view_t::x_iterator dst_it = dst.row_begin(y);
    
    for(int x=0;x<src.width(); ++x){
      *dst_it =(src_loc(0,1) - src_loc(0,-1))/ 2;
      ++dst_it;
      ++src_loc.x();
    }
  }
}


int main(){
  
  return 0;
}

