#ifdef __cplusplus
extern "C" {
#endif

#define STBI_NO_JPEG
#define STBI_NO_PNG
#define STBI_NO_BMP
#define STBI_NO_GIF
#define STBI_NO_PSD
#define STBI_NO_TGA
#define STBI_NO_PNM
#define STBI_NO_HDR

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    stbi__context s;
    stbi__start_mem(&s, data, size);

    int x, y, comp;
    stbi__result_info ri;

    void *result = stbi__pic_load(&s, &x, &y, &comp, 0, &ri);
    if (result) {
        free(result);
    }

    return 0;
}

#ifdef __cplusplus
}
#endif
