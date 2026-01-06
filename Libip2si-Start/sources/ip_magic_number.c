int ip_is_elf(char *file_header) {
    if (file_header[0] == 0x7F &&
        file_header[1] == 'E' &&
        file_header[2] == 'L' &&
        file_header[3] == 'F') {
        return (1);
    }

    return (0);
}
